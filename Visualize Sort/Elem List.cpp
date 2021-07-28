#pragma warning(disable: 6386)
#include "Elem List.h"
#include <assert.h>
#include <ctime>
#include <iostream>
template <class ElemType>
ElemList<ElemType>::ElemList(int length, int maxLength) : length_(length), maxLength_(maxLength)
{
	maxLength_ = maxLength;
	elems_ = new ElemType[maxLength_];
	assert(elems_);
	for (int i = 0; i < length_; i++)
	{
		elems_[i] = i + 1;
	}
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
template <class ElemType>
void ElemList<ElemType>::AppendElem(const ElemType& elem)
{
	if (length_ == maxLength_)
	{
		throw std::string("范围错误。");
	}
	elems_[length_++] = elem;
}
template <class ElemType>
void ElemList<ElemType>::SetLength(int length)
{
	if (length < 0)
	{
		throw std::string("范围错误。");
	}
	else if (length <= length_)
	{
		for (int i = 0; i < length; i++)
		{
			if (elems_[i] > length)
			{
				for (int j = length; j < length_; j++)
				{
					if (elems_[j] <= length)
					{
						Swap(i, j);
						break;
					}
				}
			}
		}
		length_ = length;
	}
	else if (length <= maxLength_)
	{
		for (int i = length_; i < length; i++)
		{
			elems_[i] = i + 1;
		}
		length_ = length;
	}
	else
	{
		throw std::string("范围错误。");
	}
}
template<class ElemType>
int ElemList<ElemType>::GetLength()const
{
	return length_;
}
template<class ElemType>
void ElemList<ElemType>::Swap(int firstIndex, int secondIndex)
{
	ElemType temp = elems_[firstIndex];
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
		result[i] = elems_[indexes[i]];
	}
	delete[] indexes;
	for (int i = 0; i < length_; i++)
	{
		elems_[i] = result[i];
	}
	delete[] result;
}
template <class ElemType>
ElemType& ElemList<ElemType>::operator[](int index)
{
	if (index < 0 || index >= length_)
	{
		throw std::string("范围错误。");
	}
	return elems_[index];
}
template <class ElemType>
ElemList<ElemType>& ElemList<ElemType>::operator=(const ElemList<ElemType>& list)
{
	if (&list != this)
	{
		delete[] elems_;
		length_ = list.length_;
		maxLength_ = list.maxLength_;
		elems_ = new ElemType[maxLength_];
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