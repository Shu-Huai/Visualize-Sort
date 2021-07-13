#include "Sort.h"
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