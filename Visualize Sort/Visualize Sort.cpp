#include "Elem List.h"
#include "Sort.h"
int main()
{
	int elems[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	ElemList<int> list(elems, 16, 16);
	list.HighLightAll(10);
	Sleep(1000);
	system("cls");
	list.RandomOrder();
	cout << list;
	Sleep(1000);
	Sort<int>::BubbleSort(list);
	list.HighLightAll(10);
	return 0;
}