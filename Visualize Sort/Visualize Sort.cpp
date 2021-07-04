#include "Elem List.h"
#include "Sort.h"
int main()
{
	int elems[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	ElemList<int> list(elems, 20, 20);
	list.HighLightAll(10);
	char functionSelect = 0;
	while (functionSelect != '0')
	{
		Sleep(1000);
		list.RandomOrder();
		list.HighLightAll(10);
		cout << endl << "1. 冒泡排序。" << endl << "2. 优化的冒泡排序。" << endl << "3. 鸡尾酒排序。" << endl << "4. 快速排序。" << endl << "5. 直接插入排序。" << endl
			<< "6. 二分插入排序。" << endl << "7. 希尔排序。" << endl << "8. 计数排序。" << endl << "0. 退出。" << endl << "选择功能（0~8）：  \b\b";
		cin >> functionSelect;
		switch (functionSelect)
		{
		case '1':
			Sort<int>::BubbleSort(list);
			list.HighLightAll(10);
			break;
		case '2':
			Sort<int>::OptimizedBubbleSort(list);
			list.HighLightAll(10);
			break;
		case '3':
			Sort<int>::CockTailSort(list);
			list.HighLightAll(10);
			break;
		case '4':
			Sort<int>::QuickSort(list);
			list.HighLightAll(10);
			break;
		case '5':
			Sort<int>::StraightInsertSort(list);
			list.HighLightAll(10);
			break;
		case '6':
			Sort<int>::BinaryInsertSort(list);
			list.HighLightAll(10);
			break;
		case '7':
			Sort<int>::ShellSort(list);
			list.HighLightAll(10);
			break;
		case '8':
			Sort<int>::CountSort(list);
			list.HighLightAll(10);
			break;
		}
	}
	return 0;
}