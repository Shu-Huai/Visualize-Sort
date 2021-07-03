#pragma once
#include "Elem List.h"
#include <iostream>
using namespace std;
template<class ElemType>
class Sort
{
public:
	static void BubbleSort(ElemList<ElemType>& list);
};
template<class ElemType>
void Sort<ElemType>::BubbleSort(ElemList<ElemType>& list)
{
	for (int i = 0; i < list.GetLength(); i++)
	{
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
	}
}