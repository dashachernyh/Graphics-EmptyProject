#pragma once
#include<iostream>
using namespace std;
template<class T>
class TStack
{
	T *arr;
	int size, num;
public:
	TStack(int _size = 10);
	TStack(const TStack &st);
	TStack& operator=(const TStack &st);
	void Push(T el);
	T Pop();
	T Top()const;
	bool IsEmpty()const;
	bool IsFull()const;
	void ClearSt();
};
template<class T>
TStack<T>::TStack<T>(int _size)
{
	if (_size <= 0) throw "wrong size";
	size = _size;
	arr = new T[size];
	num = -1;
}
template<class T>
TStack<T>::TStack<T>(const TStack &st)
{
	size = _size;
	arr = new T[size];
	num = st.num;
	for (int i = 0; i <= num; i++)
		arr[i] = st.arr[i];
}
template<class T>
TStack<T>& TStack<T>::operator=(const TStack &st)
{
	if (*this != st)
	{
		if (size != st.size)
		{
			size = st.size;
			delete[]arr;
			arr = new T[size];
		}
		num = st.num;
		for (int i = 0; i <= num; i++)
			arr[i] = st.arr[i];
	}
	return *this;
}
template<class T>
void TStack<T>::Push(T el)
{
	if (num == size - 1) throw "can not add new elem";
	else
	{
		arr[num + 1] = el;
		num++;
	}
}
template<class T>
T TStack<T>::Pop()
{
	if (num == -1) throw "can not get elem";
	num--;
	return arr[num + 1];
}
template<class T>
T TStack<T>::Top()const
{
	if (num == -1) throw" can not get elem";
	return arr[num];
}
template<class T>
bool TStack<T>::IsEmpty()const
{
	if (num == -1) return true;
	else return false;
}
template<class T>
bool TStack<T>::IsFull()const
{
	if (num == size - 1) return true;
	else return false;
}
template<class T>
void TStack<T>::ClearSt()
{
	num = -1;
}