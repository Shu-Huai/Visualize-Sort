#include "Elem List.h"
#include "Sort.h"
int main()
{
	int length = 0;
	while (length <= 0)
	{
		cout << "请输入元素个数：";
		cin >> length;
		system("cls");
	}
	int* elems = new int[length];
	for (int i = 0; i < length; i++)
	{
		elems[i] = i + 1;
	}
	ElemList<int> list(elems, length, length);
	delete[]elems;
	list.HighLightAll(10);
	char functionSelect = 0;
	while (functionSelect != '0')
	{
		Sleep(1000);
		list.RandomOrder();
		list.HighLightAll(10);
		cout << endl << "1. 冒泡排序。" << endl << "2. 优化的冒泡排序。" << endl << "3. 鸡尾酒排序。" << endl << "4. 快速排序。" << endl << "5. 直接插入排序。" << endl
			<< "6. 二分插入排序。" << endl << "7. 希尔排序。" << endl << "8. 计数排序。" << endl << "9. 猴子排序。" << endl << "a. 基数排序。" << endl
			<< "b. 归并排序。" << endl << "0. 退出。" << endl << "选择功能（0~8）：  \b\b";
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
		case '9':
			Sort<int>::MonkeySort(list);
			list.HighLightAll(10);
			break;
		case 'a':
			Sort<int>::RadixSort(list);
			list.HighLightAll(10);
			break;
		case 'b':
			Sort<int>::MergeSort(list);
			list.HighLightAll(10);
		}
	}
	return 0;
}