#pragma once
#include "Elem List.h"
#include <iostream>
using namespace std;
template<class ElemType>
class Sort
{
protected:
	static void QuickSort(ElemList<ElemType>& list, int low, int high);
public:
	static void BubbleSort(ElemList<ElemType>& list);
	static void OptimizedBubbleSort(ElemList<ElemType>& list);
	static void CockTailSort(ElemList<ElemType>& list);
	static void QuickSort(ElemList<ElemType>& list);
};
template <class ElemType>
void Sort<ElemType>::QuickSort(ElemList<ElemType>& list, int low, int high)
{
	if (low < high)
	{
		list.ShowRange(low, high);
		ElemType referenceValue = list[low].GetValue();
		int i = low;
		int j = high;
		while (i < j)
		{
			while (i < j && list[j] >= referenceValue)
			{
				list.HighLight(low, 100);
				list.HighLight(j, 100);
				j--;
			}
			if (i < j)
			{
				list[i] = list[j];
				i++;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
				cout << list;
			}
			while (i < j && list[i] <= referenceValue)
			{
				list.HighLight(low, 100);
				list.HighLight(i, 100);
				i++;
			}
			if (i < j)
			{
				list[j] = list[i];
				j--;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
				cout << list;
			}
		}
		list[i] = referenceValue;
		list.HideRange(low, high);
		QuickSort(list, low, i - 1);
		QuickSort(list, i + 1, high);
	}
}
template<class ElemType>
void Sort<ElemType>::BubbleSort(ElemList<ElemType>& list)
{
	for (int i = 0; i < list.GetLength(); i++)
	{
		list.ShowRange(0, list.GetLength() - i);
		for (int j = 0; j < list.GetLength() - i - 1; j++)
		{
			list.HighLight(j, 100);
			list.HighLight(j + 1, 100);
			if (list[j] > list[j + 1])
			{
				list.Swap(j, j + 1);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
				cout << list;
			}
		}
		list.HideRange(0, list.GetLength() - i);
	}
}
template<class ElemType>
void Sort<ElemType>::OptimizedBubbleSort(ElemList<ElemType>& list)
{
	for (int i = 0; i < list.GetLength(); i++)
	{
		list.ShowRange(0, list.GetLength() - i);
		bool isSwaped = false;
		for (int j = 0; j < list.GetLength() - i - 1; j++)
		{
			list.HighLight(j, 100);
			list.HighLight(j + 1, 100);
			if (list[j] > list[j + 1])
			{
				list.Swap(j, j + 1);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
				cout << list;
				isSwaped = true;
			}
		}
		list.HideRange(0, list.GetLength() - i);
		if (!isSwaped)
		{
			break;
		}
	}
}
template<class ElemType>
void Sort<ElemType>::CockTailSort(ElemList<ElemType>& list)
{
	int left = 0;
	int right = list.GetLength() - 1;
	for (int i = 0; i < list.GetLength(); i++)
	{
		list.ShowRange(i, list.GetLength() - i);
		bool isSwaped = false;
		for (int j = i; j < list.GetLength() - i - 1; j++)
		{
			list.HighLight(j, 100);
			list.HighLight(j + 1, 100);
			if (list[j] > list[j + 1])
			{
				list.Swap(j, j + 1);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
				cout << list;
				isSwaped = true;
			}
		}
		if (!isSwaped)
		{
			list.HideRange(i, list.GetLength() - i);
			break;
		}
		isSwaped = false;
		for (int j = list.GetLength() - i - 1; j > i; j--)
		{
			list.HighLight(j, 100);
			list.HighLight(j - 1, 100);
			if (list[j] < list[j - 1])
			{
				list.Swap(j, j - 1);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
				cout << list;
				isSwaped = true;
			}
		}
		list.HideRange(i, list.GetLength() - i);
		if (!isSwaped)
		{
			break;
		}
	}
}
template <class ElemType>
void Sort<ElemType>::QuickSort(ElemList<ElemType>& list)
{
	QuickSort(list, 0, list.GetLength() - 1);
}