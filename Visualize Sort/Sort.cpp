﻿#include "Sort.h"
Sort::Sort(QObject* parent) : QObject(parent)
{
}
void Sort::BubbleSort(ElemList<int>& list)
{
	for (int i = 0; i < list.GetLength(); i++)
	{
		for (int j = 0; j < list.GetLength() - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				emit BubbleSignal(j, j + 1, true);
				list.Swap(j, j + 1);
			}
			emit BubbleSignal(j, j + 1);
		}
	}
}
void Sort::OptimizedBubbleSort(ElemList<int>& list)
{
	for (int i = 0; i < list.GetLength(); i++)
	{
		bool isSwaped = false;
		for (int j = 0; j < list.GetLength() - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				emit BubbleSignal(j, j + 1, true);
				list.Swap(j, j + 1);
				isSwaped = true;
			}
			emit BubbleSignal(j, j + 1);
		}
		if (!isSwaped)
		{
			break;
		}
	}
}
void Sort::CockTailSort(ElemList<int>& list)
{
	int left = 0;
	int right = list.GetLength() - 1;
	for (int i = 0; i < list.GetLength(); i++)
	{
		bool isSwaped = false;
		for (int j = i; j < list.GetLength() - i - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				emit BubbleSignal(j, j + 1, true);
				list.Swap(j, j + 1);
				isSwaped = true;
			}
			emit BubbleSignal(j, j + 1);
		}
		if (!isSwaped)
		{
			break;
		}
		isSwaped = false;
		for (int j = list.GetLength() - i - 1; j > i; j--)
		{
			if (list[j] < list[j - 1])
			{
				emit BubbleSignal(j, j - 1, true);
				list.Swap(j, j - 1);
				emit BubbleSignal(j, j - 1);
				isSwaped = true;
			}
			emit BubbleSignal(j, j - 1);
		}
		if (!isSwaped)
		{
			break;
		}
	}
}
void Sort::QuickSort(ElemList<int>& list)
{
	QuickSort(list, 0, list.GetLength() - 1);
}
void Sort::StraightInsertSort(ElemList<int>& list)
{
	for (int i = 1; i < list.GetLength(); i++)
	{
		int j = i - 1;
		int temp = list[i];
		emit BubbleSignal(i, -1);
		for (j = i - 1; j >= 0; j--)
		{
			if (list[j] <= temp)
			{
				emit BubbleSignal(j, -1);
				break;
			}
			emit BubbleSignal(j, -1, true);
			list[j + 1] = list[j];
		}
		list[j + 1] = temp;
		emit BubbleSignal(-1, -1);
	}
}
void Sort::BinaryInsertSort(ElemList<int>& list)
{
	for (int i = 1; i < list.GetLength(); i++)
	{
		int low = 0;
		int high = i - 1;
		int middle = 0;
		int key = list[i];
		emit BubbleSignal(i, -1);
		while (low <= high)
		{
			middle = (low + high) / 2;
			emit BubbleSignal(middle, -1);
			if (list[middle] > key)
			{
				emit BubbleSignal(middle, -1, true);
				high = middle - 1;
			}
			else if (list[middle] < key)
			{
				emit BubbleSignal(middle, -1, true);
				low = middle + 1;
			}
		}
		for (int j = i - 1; j >= low; j--)
		{
			list[j + 1] = list[j];
		}
		list[low] = key;
		emit BubbleSignal(-1, -1);
	}
}
void Sort::ShellSort(ElemList<int>& list)
{
	int distance = list.GetLength() / 2;
	while (distance > 0)
	{
		for (int i = distance; i < list.GetLength(); i++)
		{
			int j = i - distance;
			int temp = list[i];
			emit BubbleSignal(i, -1);
			for (j = i - distance; j >= 0; j -= distance)
			{
				if (list[j] <= temp)
				{
					emit BubbleSignal(j, -1);
					break;
				}
				emit BubbleSignal(j, -1, true);
				list[j + distance] = list[j];
			}
			list[j + distance] = temp;
			emit BubbleSignal(-1, -1);
		}
		distance /= 2;
	}
}
void Sort::QuickSort(ElemList<int>& list, int low, int high)
{
	if (low < high)
	{
		int referenceValue = list[low];
		int i = low;
		int j = high;
		while (i < j)
		{
			while (i < j && list[j] >= referenceValue)
			{
				emit BubbleSignal(j, -1);
				j--;
			}
			if (i < j)
			{
				emit BubbleSignal(j, -1, true);
				list[i] = list[j];
				emit BubbleSignal(-1, -1);
				i++;
			}
			while (i < j && list[i] <= referenceValue)
			{
				emit BubbleSignal(i, -1);
				i++;
			}
			if (i < j)
			{
				emit BubbleSignal(i, -1, true);
				list[j] = list[i];
				emit BubbleSignal(-1, -1);
				j--;
			}
		}
		list[i] = referenceValue;
		QuickSort(list, low, i - 1);
		QuickSort(list, i + 1, high);
	}
}