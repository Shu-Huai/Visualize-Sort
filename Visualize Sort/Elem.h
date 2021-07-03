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

public:
	Elem(ElemType value = 0);
	void HighLight(short yCoordinate,int time);
	ElemType GetValue()const;
	bool operator>(const Elem<ElemType>& elem);
	bool operator>=(const Elem<ElemType>& elem);
	bool operator<(const Elem<ElemType>& elem);
	bool operator<=(const Elem<ElemType>& elem);
	template <class SubElemType>
	friend ostream& operator<<(ostream& out, const Elem<SubElemType>& elem);
	template <class SubElemType>
	friend class ElemList;
};
template <class ElemType>
Elem<ElemType>::Elem(ElemType value) : value_(value)
{
}
template<class ElemType>
void Elem<ElemType>::HighLight(short yCoordinate,int time)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,yCoordinate });
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	for (int j = 0; j < value_; j++)
	{
		cout << "  ";
	}
	cout << setw(2) << value_;
	for (int j = 0; j < 16 - value_; j++)
	{
		cout << "  ";
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,yCoordinate });
	Sleep(time);
	cout << *this;
	Sleep(time);
}
template<class ElemType>
ElemType Elem<ElemType>::GetValue()const
{
	return value_;
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
	WORD colors[16] = { 0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0 };
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WORD(colors[elem.value_ % 16]));
	for (int i = 0; i < elem.value_; i++)
	{
		out << "  ";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	out << setw(2) << elem.value_;
	for (int i = 0; i < 16 - elem.value_; i++)
	{
		out << "  ";
	}
	return out;
}