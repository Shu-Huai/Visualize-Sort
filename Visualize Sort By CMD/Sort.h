#pragma once
#pragma warning(disable:6385)
#include "Elem List.cpp"
template<class ElemType>
class Sort
{
protected:
	static void QuickSort(ElemList<ElemType>& list, int low, int high);
	static void Merge(ElemList<ElemType>& list, int low, int middle, int high);
public:
	static void BubbleSort(ElemList<ElemType>& list);
	static void OptimizedBubbleSort(ElemList<ElemType>& list);
	static void CockTailSort(ElemList<ElemType>& list);
	static void QuickSort(ElemList<ElemType>& list);
	static void StraightInsertSort(ElemList<ElemType>& list);
	static void BinaryInsertSort(ElemList<ElemType>& list);
	static void ShellSort(ElemList<ElemType>& list);
	static void CountSort(ElemList<ElemType>& list);
	static void MonkeySort(ElemList<ElemType>& list);
	static void RadixSort(ElemList<ElemType>& list);
	static void MergeSort(ElemList<ElemType>& list);
};