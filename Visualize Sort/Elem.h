#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
template <class ElemType>
class Elem
{
protected:
	ElemType value_;
	static ElemType maxValue_;

public:
	Elem(ElemType value = 0);
	void HighLight(short yCoordinate, int time);
	ElemType GetValue()const;
	ElemType GetMaxValue() const;
	bool operator>(const Elem<ElemType>& elem);
	bool operator>=(const Elem<ElemType>& elem);
	bool operator<(const Elem<ElemType>& elem);
	bool operator<=(const Elem<ElemType>& elem);
	template <class SubElemType>
	friend ostream& operator<<(ostream& out, const Elem<SubElemType>& elem);
	template <class SubElemType>
	friend class ElemList;
};
template<class ElemType>
ElemType Elem<ElemType>::maxValue_ = 0;
template <class ElemType>
Elem<ElemType>::Elem(ElemType value) : value_(value)
{
}
template<class ElemType>
void Elem<ElemType>::HighLight(short yCoordinate, int time)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,yCoordinate });
	for (int i = 0; i < maxValue_ + 1; i++)
	{
		cout << "  ";
	}
	Sleep(time);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,yCoordinate });
	cout << *this;
	Sleep(time);
}
template<class ElemType>
ElemType Elem<ElemType>::GetValue()const
{
	return value_;
}
template<class ElemType>
ElemType Elem<ElemType>::GetMaxValue()const
{
	return maxValue_;
}
template<class ElemType>
bool Elem<ElemType>::operator>(const Elem<ElemType>& elem)
{
	return value_ > elem.value_;
}
template<class ElemType>
bool Elem<ElemType>::operator>=(const Elem<ElemType>& elem)
{
	return value_ >= elem.value_;
}
template<class ElemType>
bool Elem<ElemType>::operator<(const Elem<ElemType>& elem)
{
	return value_ < elem.value_;
}
template<class ElemType>
bool Elem<ElemType>::operator<=(const Elem<ElemType>& elem)
{
	return value_ <= elem.value_;
}
template <class ElemType>
ostream& operator<<(ostream& out, const Elem<ElemType>& elem)
{
	for (int i = 0; i < elem.value_; i++)
	{
		out << "▆▆";
	}
	out << setw(3) << elem.value_;
	for (int i = 0; i < elem.maxValue_ - elem.value_; i++)
	{
		out << "  ";
	}
	return out;
}