#include "puzzle.h"
#include "ui_puzzle.h"
#include"singleton.h"
#include"end.h"
#include"settings.h"
#include"sortfactory.h"
#include <QFileDialog>

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QPointF>
#include <algorithm>
#include <QDebug>
#include <QStyle>
#include <QMouseEvent>
#include <QDebug>
#include<QSettings>
#include <QThread>


QVector<int> places;


puzzle::puzzle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::puzzle)
{

    ui->setupUi(this);


    ui->label->setVisible(false);
    if(Singleton::getInstance().IfLevels==true){
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(false);
    }
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);
    show();
    places.clear();
    picture1 = NULL;
    if(Singleton::getInstance().wayToTheElement == nullptr){
        Singleton::getInstance().wayToTheElement=":/levels/back.jpg";
        Singleton::getInstance().width=5;
    }
        QPixmap pixmap(Singleton::getInstance().wayToTheElement);
        //QPixmap pixmap(":/levels/1.jpg");
        pixmap = pixmap.scaled(1000, 1000, Qt::IgnoreAspectRatio);
        QPixmap small=pixmap;
        small = small.scaled(200, 200, Qt::IgnoreAspectRatio);
        QLabel *label=new QLabel;
        label->setPixmap(small);
        ui->gridLayout_3->addWidget(label, 0,0);
        int N = Singleton::getInstance().width;


        for(int i=0;i<N*N;i++){
            places.push_back(i);
        }

        std::random_shuffle(places.begin(), places.end());
               // std::random_shuffle(places.begin(), places.end());


        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){

                    ClickableLabel *label = new ClickableLabel();
                    label->place=places[i*N+j];
                    label->index=(i)*N+j;
                    qDebug()<<label->index;
                    qDebug()<<label->place;

                    QRect rect(j*1000/N, i*1000/N, 1000/N, 1000/N);
                    QPixmap cropped = pixmap.copy(rect);
                    cropped = cropped.scaled(1000/N/2, 1000/N/2, Qt::IgnoreAspectRatio);

                    label->setPixmap(cropped);
                    if(label->index==label->place){
                        label->setStyleSheet("border: 4px solid #FFF851;");
                    }
                    else
                    label->setStyleSheet("border: none;");

                    ClickableLabel::connect(label, SIGNAL(clicked()), this, SLOT(pic_clicked()));
                    ui->gridLayout->addWidget(label, label->place/N, label->place%N);

                }
        }

        if(!Singleton::getInstance().IfLevels){
        Singleton::getInstance().stepsForSorting.clear();
        SortFactory* sortFactory= new QuickFactory();
        switch (Singleton::getInstance().sort) {

            case 2:sortFactory=new HeapFactory();
            break;
            case 3:sortFactory=new BubbleFactory();
            break;
            case 4:sortFactory=new InsertFactory();
        }
        QVector<int> array;
        for(int i=0;i<array.size();i++){
            array[i]=i;
            array.push_back(array[i]);
        }
        Singleton::getInstance().stepsForSorting.push_back(array);
        Sort* s=sortFactory->createSort();
        s->applysort(places);
        Singleton::getInstance().step=0;
        }

}

void puzzle::showStep(){
    QLayoutItem *l1=nullptr;
    QLayoutItem *l2=nullptr;
    N=Singleton::getInstance().width;
    for(int j=0;j<places.size();j++){

        if(places[j]!=Singleton::getInstance().stepsForSorting[Singleton::getInstance().step][j] && l1!=nullptr){
            l2=ui->gridLayout->itemAtPosition(j/N, j%N);


            swapElements(l1,l2);
            l1=nullptr;
            l2=nullptr;


        }
        if(places[j]!=Singleton::getInstance().stepsForSorting[Singleton::getInstance().step][j] && l1==nullptr)
            l1=ui->gridLayout->itemAtPosition(j/N, j%N);

    }
}

void puzzle::updateTime()
{


    QThread::msleep(500);
}



void puzzle::swapElements(QLayoutItem *l1,QLayoutItem *l2){


    ClickableLabel *a=static_cast<ClickableLabel*>(l1->widget());
    ClickableLabel *b=static_cast<ClickableLabel*>(l2->widget());
    picture1=a;
    b->emitClick();

}


void puzzle::help(){
    bool q=false;
    for(int i=0;i<places.size();i++){
      if(places[i]!=i && q==false){
          QLayoutItem *l1=ui->gridLayout->itemAtPosition(i/N, i%N);
          QLayoutItem *l2=ui->gridLayout->itemAtPosition(places[i]/N, places[i]%N);
          swapElements(l1,l2);
          q=true;
          break;
    }
}

}

void puzzle::sort()
{
    int n=places.size();
    N=Singleton::getInstance().width;
   int j;
   for (j = 0; j < n; j++){

       if(places[j]!=j){
           QLayoutItem *l1=ui->gridLayout->itemAtPosition(j/N, j%N);
           QLayoutItem *l2=ui->gridLayout->itemAtPosition(places[j]/N, places[j]%N);
           swapElements(l1,l2);
           j--;
       }


   }


}



void puzzle::pic_clicked()
{

    ClickableLabel* obj = (ClickableLabel*)sender();


    if(picture1==NULL){
        picture1=obj;

    }
    else if(picture1==obj){
        picture1=NULL;
}
    else {
        //qDebug()<< "picture1  "<< picture1->index;
        //qDebug()<< "obj                 "<< obj->index;


        auto gp = qMakePair(-1,-1);
        int index = ui->gridLayout->indexOf(obj);
        int rs,cs;
        ui->gridLayout->getItemPosition(index, &gp.first, &gp.second, &rs, &cs);


        auto gp1 = qMakePair(-1,-1);
        int index1 = ui->gridLayout->indexOf(picture1);
        int rs1,cs1;
        ui->gridLayout->getItemPosition(index1, &gp1.first, &gp1.second, &rs1, &cs1);

        //qDebug()<< "picture1 1 "<< picture1->index<<"  "<<picture1->place;
        //qDebug()<< "obj                 "<< obj->index<<"  "<<obj->place;
        ui->gridLayout->removeWidget(picture1);
        ui->gridLayout->removeWidget(obj);
        ui->gridLayout->addWidget(picture1, gp.first, gp.second);
        ui->gridLayout->addWidget(obj, gp1.first, gp1.second);


        int var=picture1->place;
        picture1->place=obj->place;
        obj->place=var;


      places[picture1->index]=picture1->place;
      places[obj->index]=obj->place;





            if(obj->place==obj->index){
                obj->setStyleSheet("border: 4px solid #FFF851; ");

            }
            if(obj->place != obj->index) {
                obj->setStyleSheet("border: none;");
            }
            if(picture1->place == picture1->index){
                picture1->setStyleSheet("border: 4px solid #FFF851;");
            }
            if(picture1->place != picture1->index) {
                picture1->setStyleSheet("border: none;");
            }




        picture1 = NULL;


    }


    if(IfFinished(places)){


            if(Singleton::getInstance().IfLevels==true){
                ui->label->setVisible(true);
            }
           //checking if this level was visited earlier
           if(Singleton::getInstance().IfLevels==true){
               bool a=false;
               for(int i=0; i<Singleton::getInstance().visitedLevels.size();i++){
                   if(Singleton::getInstance().visitedLevels[i]==Singleton::getInstance().sublevel){
                       a=true;
                   }
               }
               if(a==false){
                   bool ifNew=true;
                   for(int i=0; i< Singleton::getInstance().visitedLevels.size();i++){
                       if(Singleton::getInstance().wayToTheElement== Singleton::getInstance().visitedLevels[i])
                           ifNew=false;
                   }
                   if(ifNew){
                       Singleton::getInstance().NumberOfStars+=5;

                   }
                   Singleton::getInstance().visitedLevels.push_back(Singleton::getInstance().wayToTheElement);
               }
           }
           if(Singleton::getInstance().IfLevels==true){
               close();
               End w;
               w.setModal(true);
               w.exec();

           }
              Singleton::getInstance().IfLevels=false;
              Singleton::getInstance().wayToTheElement=nullptr;
              Singleton::getInstance().sublevel=0;



    }

}

bool puzzle::IfFinished(QVector<int> places){
    int trueN =0;
    for(int i=0;i<places.size();i++){
        if(places[i]==i){
            trueN++;
        }
    }
    if(trueN==places.size())
        return true;
    else {
       return false;
    }
}

puzzle::~puzzle()
{
    delete ui;
}

void puzzle::on_pushButton_clicked()
{

    Settings w;
    w.setModal(true);
    w.exec();
}





void puzzle::on_pushButton_2_clicked()
{
    sort();
    //help();
}

void puzzle::on_pushButton_3_clicked()
{

    close();
    End w;
    w.setModal(true);
    w.exec();

}

void puzzle::on_pushButton_5_clicked()
{
    if(Singleton::getInstance().step<Singleton::getInstance().stepsForSorting.size() &&Singleton::getInstance().step>0){
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
    }

    if(Singleton::getInstance().step+1<Singleton::getInstance().stepsForSorting.size())
        Singleton::getInstance().step++;
     if(Singleton::getInstance().step+1==Singleton::getInstance().stepsForSorting.size()){
        ui->pushButton_5->setEnabled(false);
    }
    showStep();

}

void puzzle::on_pushButton_4_clicked()
{
    if(Singleton::getInstance().step<Singleton::getInstance().stepsForSorting.size() &&Singleton::getInstance().step>0){
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
    }
    if(Singleton::getInstance().step-1>0)
        Singleton::getInstance().step--;
     if(Singleton::getInstance().step-1==0){
        ui->pushButton_4->setEnabled(false);
    }
    showStep();

}


