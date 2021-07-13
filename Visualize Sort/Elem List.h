#pragma once
template <class ElemType>
class ElemList
{
protected:
	ElemType* elems_;
	int length_;
	int maxLength_;
public:
	ElemList(int length = 1000, int maxLength = 1000);
	~ElemList();
	bool IsSorted()const;
	void AppendElem(const ElemType& elem);
	void SetLength(int length);
	int GetLength()const;
	void Swap(int firstIndex, int secondIndex);
	void RandomOrder();
	ElemType& operator[](int index);
	ElemList<ElemType>& operator=(const ElemList<ElemType>& list);
};