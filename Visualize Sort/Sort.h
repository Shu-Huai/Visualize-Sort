#pragma once
#include <iostream>
#include <qobject.h>
#include "Elem List.cpp"
class Sort :public QObject
{
	Q_OBJECT
public:
	Sort(QObject* parent = NULL);
	void BubbleSort(ElemList<int>& list);
	//	static void OptimizedBubbleSort(ElemList<int>& list);
	//	static void CockTailSort(ElemList<int>& list);
	//	static void QuickSort(ElemList<int>& list);
	//	static void StraightInsertSort(ElemList<int>& list);
	//	static void BinaryInsertSort(ElemList<int>& list);
	//	static void ShellSort(ElemList<int>& list);
	//	static void CountSort(ElemList<int>& list);
	//	static void MonkeySort(ElemList<int>& list);
	//	static void RadixSort(ElemList<int>& list);
	//	static void MergeSort(ElemList<int>& list);
	//protected:
	//	static void QuickSort(ElemList<int>& list, int low, int high);
	//	static void Merge(ElemList<int>& list, int low, int middle, int high);
signals:
	void BubbleSignal(int firstIndex, int secondIndex, bool neededSwap = false);
};
//void Sort::QuickSort(ElemList<int>& list, int low, int high)
//{
//	if (low < high)
//	{
//		list.ShowRange(low, high);
//		int referenceValue = list[low];
//		int i = low;
//		int j = high;
//		list.HighLight(low, 2000 / list.GetLength());
//		while (i < j)
//		{
//			while (i < j && list[j] >= referenceValue)
//			{
//				list.HighLight(j, 2000 / list.GetLength());
//				j--;
//			}
//			if (i < j)
//			{
//				list[i] = list[j];
//				i++;
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//				cout << list;
//			}
//			while (i < j && list[i] <= referenceValue)
//			{
//				list.HighLight(i, 2000 / list.GetLength());
//				i++;
//			}
//			if (i < j)
//			{
//				list[j] = list[i];
//				j--;
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//				cout << list;
//			}
//		}
//		list[i] = referenceValue;
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//		cout << list;
//		list.HideRange(low, high);
//		QuickSort(list, low, i - 1);
//		QuickSort(list, i + 1, high);
//	}
//}
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
//void Sort::OptimizedBubbleSort(ElemList<int>& list)
//{
//	for (int i = 0; i < list.GetLength(); i++)
//	{
//		list.ShowRange(0, list.GetLength() - i);
//		bool isSwaped = false;
//		for (int j = 0; j < list.GetLength() - i - 1; j++)
//		{
//			list.HighLight(j, 2000 / list.GetLength());
//			list.HighLight(j + 1, 2000 / list.GetLength());
//			if (list[j] > list[j + 1])
//			{
//				list.Swap(j, j + 1);
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//				cout << list;
//				isSwaped = true;
//			}
//		}
//		list.HideRange(0, list.GetLength() - i);
//		if (!isSwaped)
//		{
//			break;
//		}
//	}
//}
//void Sort::CockTailSort(ElemList<int>& list)
//{
//	int left = 0;
//	int right = list.GetLength() - 1;
//	for (int i = 0; i < list.GetLength(); i++)
//	{
//		list.ShowRange(i, list.GetLength() - i);
//		bool isSwaped = false;
//		for (int j = i; j < list.GetLength() - i - 1; j++)
//		{
//			list.HighLight(j, 2000 / list.GetLength());
//			list.HighLight(j + 1, 2000 / list.GetLength());
//			if (list[j] > list[j + 1])
//			{
//				list.Swap(j, j + 1);
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//				cout << list;
//				isSwaped = true;
//			}
//		}
//		list.HideRange(i, list.GetLength() - i);
//		list.ShowRange(i, list.GetLength() - i - 1);
//		if (!isSwaped)
//		{
//			break;
//		}
//		isSwaped = false;
//		for (int j = list.GetLength() - i - 1; j > i; j--)
//		{
//			list.HighLight(j, 2000 / list.GetLength());
//			list.HighLight(j - 1, 2000 / list.GetLength());
//			if (list[j] < list[j - 1])
//			{
//				list.Swap(j, j - 1);
//				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//				cout << list;
//				isSwaped = true;
//			}
//		}
//		list.HideRange(i, list.GetLength() - i - 1);
//		if (!isSwaped)
//		{
//			break;
//		}
//	}
//}
//void Sort::QuickSort(ElemList<int>& list)
//{
//	QuickSort(list, 0, list.GetLength() - 1);
//}
//void Sort::StraightInsertSort(ElemList<int>& list)
//{
//	for (int i = 1; i < list.GetLength(); i++)
//	{
//		list.ShowRange(0, i + 1);
//		int j = i - 1;
//		ElemType temp = list[i].GetValue();
//		list.HighLight(i, 2000 / list.GetLength());
//		for (j = i - 1; j >= 0; j--)
//		{
//			list.HighLight(j, 2000 / list.GetLength());
//			if (list[j] <= temp)
//			{
//				break;
//			}
//			list[j + 1] = list[j];
//		}
//		list[j + 1] = temp;
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//		cout << list;
//		list.HideRange(0, i + 1);
//	}
//}
//void Sort::BinaryInsertSort(ElemList<int>& list)
//{
//	for (int i = 1; i < list.GetLength(); i++)
//	{
//		list.ShowRange(0, i + 1);
//		int low = 0;
//		int high = i - 1;
//		int middle = 0;
//		ElemType key = list[i].GetValue();
//		list.HighLight(i, 2000 / list.GetLength());
//		while (low <= high)
//		{
//			middle = (low + high) / 2;
//			list.HighLight(middle, 2000 / list.GetLength());
//			if (list[middle] > key)
//			{
//				high = middle - 1;
//			}
//			else if (list[middle] < key)
//			{
//				low = middle + 1;
//			}
//		}
//		for (int j = i - 1; j >= low; j--)
//		{
//			list[j + 1] = list[j];
//		}
//		list[low] = key;
//		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//		cout << list;
//		list.HideRange(0, i + 1);
//	}
//}
//void Sort::ShellSort(ElemList<int>& list)
//{
//	int distance = list.GetLength() / 2;
//	while (distance > 0)
//	{
//		for (int i = distance; i < list.GetLength(); i++)
//		{
//			int j = i - distance;
//			ElemType temp = list[i].GetValue();
//			for (j = i; j >= 0; j -= distance)
//			{
//				list.ShowRange(j, j + 1);
//			}
//			list.HighLight(i, 2000 / list.GetLength());
//			for (j = i - distance; j >= 0; j -= distance)
//			{
//				list.HighLight(j, 2000 / list.GetLength());
//				if (list[j] <= temp)
//				{
//					break;
//				}
//				list[j + distance] = list[j];
//			}
//			list[j + distance] = temp;
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
//			cout << list;
//			for (j = i; j >= 0; j -= distance)
//			{
//				list.HideRange(j, j + 1);
//			}
//		}
//		distance /= 2;
//	}
//}
//void Sort::CountSort(ElemList<int>& list)
//{
//	int* indexes = new int[list.GetLength()]{ 0 };
//	for (int i = 0; i < list.GetLength(); i++)
//	{
//		for (int j = 0; j < list.GetLength(); j++)
//		{
//			if (i == j)
//			{
//				continue;
//			}
//			list.HighLight(i, 2000 / list.GetLength());
//			list.HighLight(j, 2000 / list.GetLength());
//			if (list[j] < list[i])
//			{
//				indexes[i]++;
//			}
//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ short(list.GetLength() * 2 + 3),short(i) });
//			cout << setw(2) << indexes[i];
//		}
//	}
//	ElemList<int> result(list.GetLength());
//	for (int i = 0; i < list.GetLength(); i++)
//	{
//		result.AppendElem(i);
//	}
//	for (int i = 0; i < list.GetLength(); i++)
//	{
//		result[indexes[i]] = list[i];
//	}
//	list = result;
//	delete[] indexes;
//	list.HideRange(0, list.GetLength());
//}
//void Sort::MonkeySort(ElemList<int>& list)
//{
//	bool isSorted = list.IsSorted();
//	while (!isSorted)
//	{
//		list.ShowRange(0, list.GetLength());
//		list.HighLightAll(10);
//		list.RandomOrder();
//		isSorted = list.IsSorted();
//		list.HideRange(0, list.GetLength());
//	}
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