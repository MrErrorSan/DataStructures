#pragma once
#include <iostream>
using namespace std;
//Template Stack Class
template <typename T>
class stack
{
	int size, top, capacity;
	T *arr;
public:
stack(int size = 0)
	{
	//	cout << "stack() called" << endl;
		if (size > 0)
		{
			this->capacity = size;
			this->size = 0;
			this->top = -1;
			this->arr = new T[capacity];
		}
		else
		{
			this->size = capacity = 0;
			this->arr = nullptr;
			this->top = -1;
		}
	}
stack(const stack<T> &obj)
	{
		cout << "stack copy() called" << endl;
		this->size = obj.size;
		this->capacity = obj.capacity;
		this->top = obj.top;
		//Initialize Values
		this->arr = new T[this->size];
		//copying stack
		for (int i = 0; i < this->size; i++)
			this->arr[i] = obj.arr[i];
	}
void Push(const T& obj)
	{
		//cout << "Push() called" << endl;
		if (this->size < this->capacity)
		{
			this->arr[++top] = obj;
			size++;
		}
		else if (this->capacity == 0)
		{
			this->arr = new T[1];
			arr[++top] = obj;
			size = capacity = 1;
		}
		else
		{
			//Growing
			T* temp = new T[2 * capacity];
			//copying values
			for (int i = 0; i < size; i++)
				temp[i] = arr[i];
			temp[++top] = obj;
			size++;
			capacity *= 2;
			delete[] arr;
			arr = temp;
		}
	}
void Pop()
	{
		if (this->Empty())
			return;
		else if (this->size > capacity / 2)
		{
			size--;
			top--;
		}
		else
		{
			//Shrinking
			T* temp = new T[capacity / 2];
			//Copying Values
			for (int i = 0; i < size; i++)
				temp[i] = arr[i];
			capacity /= 2;
			size--;
			top--;
			delete[] arr;
			arr = temp;
		}
	}
bool Empty()
	{
		return size == 0 ? 1 : 0;
	}
bool Full()
	{
		return size == capacity ? 1 : 0;
	}
T Peek()
	{
		if (this->Empty())
			return NULL;
		return this->arr[top];
	}
~stack()
{
	delete [] arr;
}
};