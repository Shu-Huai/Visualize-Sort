#pragma once
#include <iostream>
using namespace std;
template <class ElemType>
class Elem
{
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
private:
	ElemType value_;
	static ElemType maxValue_;
};