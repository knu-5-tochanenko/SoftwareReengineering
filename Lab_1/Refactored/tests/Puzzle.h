#pragma once
#include<QVector>
// example class to test
class Puzzle
{
public:

    QVector<int> MakeArray( int x) {
        QVector<int> a;
        a.clear();
        for(int i=0;i<x;i++){
            a.push_back(x);
        }
        return a;
        }
    bool IfFinished(QVector<int> places){
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
    bool IfRepeated(QVector<int> places){
        for(int i=1;i<places.size();i++){
            for(int j=0;j<i;j++){
                if(places[j]==places[i])
                    return true;
            }
        }
        return false;
    }

    bool IfIsNotOutOfRange(QVector<int> places){
        for(int i=0;i<places.size();i++){
            if(places[i]>places.size()-1)
                return false;
        }
        return true;

    }



private:
    QVector<int> mA;
};

