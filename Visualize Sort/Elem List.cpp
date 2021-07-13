#include "Elem List.h"
#include <ctime>
template <class ElemType>
ElemList<ElemType>::ElemList(int maxLength) : length_(0), maxLength_(maxLength)
{
	elems_ = new Elem<ElemType>[maxLength_];
}
template <class ElemType>
ElemList<ElemType>::ElemList(ElemType* elems, int length, int maxLength) : length_(length), maxLength_(maxLength)
{
	if (length_ < 0)
	{
		throw string("长度过小。");
	}
	if (length_ > maxLength_)
	{
		throw string("长度过大。");
	}
	elems_ = new Elem<ElemType>[maxLength_];
	for (int i = 0; i < length_; i++)
	{
		elems_[i].value_ = elems[i];
	}
	Elem<ElemType>::maxValue_ = length_;
}
template <class ElemType>
ElemList<ElemType>::~ElemList()
{
	delete[] elems_;
}
template<class ElemType>
bool ElemList<ElemType>::IsSorted()const
{
	for (int i = 0; i < length_ - 1; i++)
	{
		if (elems_[i] > elems_[i + 1])
		{
			return false;
		}
	}
	return true;
}
template<class ElemType>
void ElemList<ElemType>::HighLightAll(int time)const
{
	for (int i = 0; i < length_; i++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,short(i) });
		elems_[i].HighLight(i, time);
	}
}
template<class ElemType>
void ElemList<ElemType>::HighLight(int yCoordinate, int time)const
{
	elems_[yCoordinate].HighLight(yCoordinate, time);
}
template<class ElemType>
void ElemList<ElemType>::ShowRange(int firstIndex, int secondIndex) const
{
	for (short j = firstIndex; j < secondIndex; j++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ short(length_ * 2 + 3),j });
		cout << "█";
	}
}
template<class ElemType>
void ElemList<ElemType>::HideRange(int firstIndex, int secondIndex) const
{
	for (short j = firstIndex; j < secondIndex; j++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ short(length_ * 2 + 3),j });
		cout << "  ";
	}
}
template <class ElemType>
void ElemList<ElemType>::AppendElem(const ElemType& elem)
{
	if (length_ == maxLength_)
	{
		throw string("范围错误。");
	}
	elems_[length_++] = elem;
}
template<class ElemType>
int ElemList<ElemType>::GetLength()const
{
	return length_;
}
template<class ElemType>
void ElemList<ElemType>::Swap(int firstIndex, int secondIndex)
{
	Elem<ElemType> temp = elems_[firstIndex];
	elems_[firstIndex] = elems_[secondIndex];
	elems_[secondIndex] = temp;
}
template <class ElemType>
void ElemList<ElemType>::RandomOrder()
{
	int* indexes = new int[length_];
	srand(unsigned(time(0)));
	for (int i = 0; i < length_; i++)
	{
		bool isPresented = true;
		int index = 0;
		while (isPresented)
		{
			index = rand() % length_;
			isPresented = false;
			for (int j = 0; j < i; j++)
			{
				if (index == indexes[j])
				{
					isPresented = true;
					break;
				}
			}
		}
		indexes[i] = index;
	}
	ElemType* result = new ElemType[length_];
	for (int i = 0; i < length_; i++)
	{
		result[i] = elems_[indexes[i]].value_;
	}
	delete[] indexes;
	for (int i = 0; i < length_; i++)
	{
		elems_[i].value_ = result[i];
	}
	delete[] result;
}
template <class ElemType>
Elem<ElemType>& ElemList<ElemType>::operator[](int index)
{
	if (index < 0 || index >= length_)
	{
		throw string("范围错误。");
	}
	return elems_[index];
}
template <class ElemType>
ElemList<ElemType>& ElemList<ElemType>::operator=(const ElemList<ElemType>& list)
{
	if (&list != this)
	{
		delete[] elems_;
		maxLength_ = list.maxLength_;
		length_ = list.length_;
		elems_ = new Elem<ElemType>[maxLength_];
		for (int i = 0; i < length_; i++)
		{
			for (int i = 0; i < length_; i++)
			{
				elems_[i] = list.elems_[i];
			}
		}
	}
	return *this;
}
template <class ElemType>
ostream& operator<<(ostream& out, const ElemList<ElemType>& list)
{
	for (int i = 0; i < list.length_; i++)
	{
		out << list.elems_[i] << endl;
	}
	return out;
}