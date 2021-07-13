#pragma once
#pragma warning(disable:6386)
#include "Elem.cpp"
template <class ElemType>
class ElemList
{
public:
	ElemList(int maxLength = 1000);
	ElemList(ElemType* elems, int length, int maxLength = 1000);
	~ElemList();
	bool IsSorted()const;
	void HighLightAll(int time)const;
	void HighLight(int yCoordinate, int time)const;
	void ShowRange(int firstIndex, int secondIndex)const;
	void HideRange(int firstIndex, int secondIndex)const;
	void AppendElem(const ElemType& elem);
	int GetLength()const;
	void Swap(int firstIndex, int secondIndex);
	void RandomOrder();
	Elem<ElemType>& operator[](int index);
	ElemList<ElemType>& operator=(const ElemList<ElemType>& list);
	template <class SubElemType>
	friend ostream& operator<<(ostream& out, const ElemList<SubElemType>& list);
private:
	Elem<ElemType>* elems_;
	int length_;
	int maxLength_;
};