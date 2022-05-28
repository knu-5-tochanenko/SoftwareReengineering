#pragma once

#include "Puzzle.h"

#include <QtTest>

class TestPuzzle: public QObject
{
	Q_OBJECT

private slots:
	// -- setup/cleanup --
	void init();

	// -- tests --
    void testIfFinished();
    void testIfRepeated();
    void testIfIsNotOutOfRange();

private:
    QVector<int> arr1;
    QVector<int> arr2;
    QVector<int> arr3;

private:
    Puzzle mCalc;
};
