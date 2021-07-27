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
	//	static void RadixSort(ElemList<int>& list);
	//	static void MergeSort(ElemList<int>& list);
protected:
	void QuickSort(ElemList<int>& list, int low, int high);
	//	static void Merge(ElemList<int>& list, int low, int middle, int high);
signals:
	void BubbleSignal(int firstIndex, int secondIndex, bool neededSwap = false);
};
//void Sort::Merge(ElemList<int>& list, int low, int middle, int high)
//{
//	list.ShowRange(low, high + 1);
//	ElemList<int> result(high + 1);
//	for (int i = 0; i < high + 1; i++)
//	{
//		result.AppendElem(0);
//	}
//	int i = low;
//	int j = middle + 1;
//	int k = low;
//	while (i <= middle && j <= high)
//	{
//		list.HighLight(i, 2000 / list.GetLength());
//		list.HighLight(j, 2000 / list.GetLength());
//		if (list[i] <= list[j])
//		{
//			result[k] = list[i];
//			i++;
//		}
//		else
//		{
//			result[k] = list[j];
//			j++;
//		}
//		k++;
//	}
//	while (i <= middle)
//	{
//		list.HighLight(i, 2000 / list.GetLength());
//		result[k] = list[i];
//		k++;
//		i++;
//	}
//	while (j <= high)
//	{
//		list.HighLight(j, 2000 / list.GetLength());
//		result[k] = list[j];
//		k++;
//		j++;
//	}
//	for (k = low; k <= high; k++)
//	{
//		list[k] = result[k];
//	}
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//	cout << list;
//	list.HideRange(low, high + 1);
//}
//void Sort::RadixSort(ElemList<int>& list)
//{
//	for (int i = 1; list[0].GetMaxValue() / i > 0; i *= 10)
//	{
//		int* counts = new int[10]{ 0 };
//		for (int j = 0; j < list.GetLength(); j++)
//		{
//			counts[(list[j].GetValue() / i) % 10]++;
//		}
//		list.HighLightAll(2000 / list.GetLength());
//		for (int j = 0; j < list.GetLength(); j++)
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ short(list.GetLength() * 2 + 3),short(j) });
//			cout << setw(2) << counts[(list[j].GetValue() / i) % 10];
//		}
//		int* indexes = new int[10]{ 0 };
//		for (int j = 1; j < 10; j++)
//		{
//			indexes[j] = indexes[j - 1] + counts[j - 1];
//		}
//		list.HighLightAll(2000 / list.GetLength());
//		for (int j = 0; j < list.GetLength(); j++)
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ short(list.GetLength() * 2 + 3),short(j) });
//			cout << setw(2) << indexes[(list[j].GetValue() / i) % 10];
//		}
//		delete[]counts;
//		ElemType* result = new ElemType[list.GetLength()]{ 0 };
//		for (int j = 0; j < list.GetLength(); j++)
//		{
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ short(list.GetLength() * 2 + 3),short(j) });
//			cout << setw(2) << indexes[(list[j].GetValue() / i) % 10];
//			result[indexes[(list[j].GetValue() / i) % 10]] = list[j].GetValue();
//			indexes[(list[j].GetValue() / i) % 10]++;
//			list.HighLight(j, 2000 / list.GetLength());
//		}
//		delete[]indexes;
//		for (int j = 0; j < list.GetLength(); j++)
//		{
//			list[j] = result[j];
//		}
//		list.HighLightAll(10);
//		list.HideRange(0, list.GetLength());
//		delete[]result;
//	}
//}
//void Sort::MergeSort(ElemList<int>& list)
//{
//	int intervalLength = 1;
//	while (intervalLength < list.GetLength())
//	{
//		int index = 0;
//		while (index + 2 * intervalLength <= list.GetLength())
//		{
//			Merge(list, index, index + intervalLength - 1, index + 2 * intervalLength - 1);
//			index += 2 * intervalLength;
//		}
//		if (index + intervalLength < list.GetLength())
//		{
//			Merge(list, index, index + intervalLength - 1, list.GetLength() - 1);
//		}
//		intervalLength *= 2;
//	}
//}