#pragma once
#include <iostream>
#include <QObject>
#include "Elem List.cpp"
class Sort :public QObject
{
	Q_OBJECT
public:
	Sort(QObject* parent = NULL);
	void BubbleSort(ElemList<int>& list);
	void OptimizedBubbleSort(ElemList<int>& list);
	void CockTailSort(ElemList<int>& list);
	void QuickSort(ElemList<int>& list);
	void StraightInsertSort(ElemList<int>& list);
	void BinaryInsertSort(ElemList<int>& list);
	void ShellSort(ElemList<int>& list);
	void CountSort(ElemList<int>& list);
	void MonkeySort(ElemList<int>& list);
	void RadixSort(ElemList<int>& list);
	void MergeSort(ElemList<int>& list);
public slots:
	void SetTime(int time);
protected:
	int time_;
	void QuickSort(ElemList<int>& list, int low, int high);
	void Merge(ElemList<int>& list, int low, int middle, int high);
signals:
	void RepaintSignal(int firstIndex, int secondIndex, bool neededSwap = false);
};