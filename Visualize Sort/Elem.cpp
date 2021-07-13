#include "Elem.h"
#include <windows.h>
#include <iomanip>
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