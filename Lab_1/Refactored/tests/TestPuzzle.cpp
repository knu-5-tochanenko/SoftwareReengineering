#include "TestPuzzle.h"

// -- setup/cleanup --
void TestPuzzle::init()
{
    int size=10;
    arr1.clear();
    arr2.clear();
    arr3.clear();
    for(int i=0;i<size;i++){
        arr1.push_back(i);
        arr2.push_back(2);
        arr3.push_back(size+i);
    }
    arr3.pop_back();
    QCOMPARE(arr1.size(), size);
    QCOMPARE(arr2.size(), size);
    QCOMPARE(arr3.size(), size-1);

}

// -- tests --
void TestPuzzle::testIfFinished()
{
    Puzzle a1;
    a1.IfFinished(arr1);
    QCOMPARE(a1.IfFinished(arr1), true);
    QCOMPARE(a1.IfFinished(arr2), false);
    QCOMPARE(a1.IfFinished(arr3), false);
}

void TestPuzzle::testIfRepeated()
{
    Puzzle a;
    a.IfRepeated(arr1);

    QCOMPARE(a.IfRepeated(arr1), false);
    QCOMPARE(a.IfRepeated(arr2), true);
    QCOMPARE(a.IfRepeated(arr3), false);
}

void TestPuzzle::testIfIsNotOutOfRange(){
    Puzzle a;
    a.IfIsNotOutOfRange(arr1);
    QCOMPARE(a.IfIsNotOutOfRange(arr1), true);
    QCOMPARE(a.IfIsNotOutOfRange(arr2), true);
    QCOMPARE(a.IfIsNotOutOfRange(arr3), false);
}

// generate basic main: no GUI, no events
QTEST_APPLESS_MAIN(TestPuzzle)

// uncomment next line if class declaration is in .cpp (no .h)
//#include "TestPuzzle.moc"
