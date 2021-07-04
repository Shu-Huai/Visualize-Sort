#pragma once
#pragma warning(disable:63000/list.GetLength()5)
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
	static void StraightInsertSort(ElemList<ElemType>& list);
	static void BinaryInsertSort(ElemList<ElemType>& list);
	static void ShellSort(ElemList<ElemType>& list);
	static void CountSort(ElemList<ElemType>& list);
	static void MonkeySort(ElemList<ElemType>& list);
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
				list.HighLight(low, 2000 / list.GetLength() );
				list.HighLight(j, 2000 / list.GetLength() );
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
				list.HighLight(low, 2000 / list.GetLength() );
				list.HighLight(i, 2000 / list.GetLength() );
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
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
		cout << list;
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
			list.HighLight(j, 2000 / list.GetLength() );
			list.HighLight(j + 1, 2000 / list.GetLength() );
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
			list.HighLight(j, 2000 / list.GetLength() );
			list.HighLight(j + 1, 2000 / list.GetLength() );
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
			list.HighLight(j, 2000 / list.GetLength() );
			list.HighLight(j + 1, 2000 / list.GetLength() );
			if (list[j] > list[j + 1])
			{
				list.Swap(j, j + 1);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
				cout << list;
				isSwaped = true;
			}
		}
		list.HideRange(i, list.GetLength() - i);
		list.ShowRange(i, list.GetLength() - i - 1);
		if (!isSwaped)
		{
			break;
		}
		isSwaped = false;
		for (int j = list.GetLength() - i - 1; j > i; j--)
		{
			list.HighLight(j, 2000 / list.GetLength() );
			list.HighLight(j - 1, 2000 / list.GetLength() );
			if (list[j] < list[j - 1])
			{
				list.Swap(j, j - 1);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
				cout << list;
				isSwaped = true;
			}
		}
		list.HideRange(i, list.GetLength() - i - 1);
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
template <class ElemType>
void Sort<ElemType>::StraightInsertSort(ElemList<ElemType>& list)
{
	for (int i = 1; i < list.GetLength(); i++)
	{
		list.ShowRange(0, i + 1);
		int j = i - 1;
		ElemType temp = list[i].GetValue();
		list.HighLight(i, 2000 / list.GetLength() );
		for (j = i - 1; j >= 0; j--)
		{
			list.HighLight(j, 2000 / list.GetLength() );
			if (list[j] <= temp)
			{
				break;
			}
			list[j + 1] = list[j];
		}
		list[j + 1] = temp;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
		cout << list;
		list.HideRange(0, i + 1);
	}
}
template <class ElemType>
void Sort<ElemType>::BinaryInsertSort(ElemList<ElemType>& list)
{
	for (int i = 1; i < list.GetLength(); i++)
	{
		list.ShowRange(0, i + 1);
		int low = 0;
		int high = i - 1;
		int middle = 0;
		ElemType key = list[i].GetValue();
		list.HighLight(i, 2000 / list.GetLength() );
		while (low <= high)
		{
			middle = (low + high) / 2;
			list.HighLight(middle, 2000 / list.GetLength() );
			if (list[middle] > key)
			{
				high = middle - 1;
			}
			else if (list[middle] < key)
			{
				low = middle + 1;
			}
		}
		for (int j = i - 1; j >= low; j--)
		{
			list[j + 1] = list[j];
		}
		list[low] = key;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
		cout << list;
		list.HideRange(0, i + 1);
	}
}
template <class ElemType>
void Sort<ElemType>::ShellSort(ElemList<ElemType>& list)
{
	int distance = list.GetLength() / 2;
	while (distance > 0)
	{
		for (int i = distance; i < list.GetLength(); i++)
		{
			int j = i - distance;
			ElemType temp = list[i].GetValue();
			for (j = i; j >= 0; j -= distance)
			{
				list.ShowRange(j, j + 1);
			}
			list.HighLight(i, 2000 / list.GetLength() );
			for (j = i - distance; j >= 0; j -= distance)
			{
				list.HighLight(j, 2000 / list.GetLength() );
				if (list[j] <= temp)
				{
					break;
				}
				list[j + distance] = list[j];
			}
			list[j + distance] = temp;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });
			cout << list;
			for (j = i; j >= 0; j -= distance)
			{
				list.HideRange(j, j + 1);
			}
		}
		distance /= 2;
	}
}
template <class ElemType>
void Sort<ElemType>::CountSort(ElemList<ElemType>& list)
{
	int* indexes = new int[list.GetLength()]{ 0 };
	for (int i = 0; i < list.GetLength(); i++)
	{
		for (int j = 0; j < list.GetLength(); j++)
		{
			if (i == j)
			{
				continue;
			}
			list.HighLight(i, 2000 / list.GetLength() );
			list.HighLight(j, 2000 / list.GetLength() );
			if (list[j] < list[i])
			{
				indexes[i]++;
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ short(list.GetLength() * 2 + 3),short(i) });
			cout << setw(2) << indexes[i];
		}
	}
	ElemList<ElemType> result(list.GetLength());
	for (int i = 0; i < list.GetLength(); i++)
	{
		result.AppendElem(i);
	}
	for (int i = 0; i < list.GetLength(); i++)
	{
		result[indexes[i]] = list[i];
	}
	list = result;
	delete[] indexes;
	list.HideRange(0, list.GetLength());
}
template <class ElemType>
void Sort<ElemType>::MonkeySort(ElemList<ElemType>& list)
{
	bool isSorted = list.IsSorted();
	while (!isSorted)
	{
		list.ShowRange(0, list.GetLength());
		list.HighLightAll(10);
		list.RandomOrder();
		isSorted = list.IsSorted();
		list.HideRange(0, list.GetLength());
	}
}