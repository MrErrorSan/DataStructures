#include<iostream>
using namespace std;
class stack 
{
private:
	int top,size,capacity;
	char* arr;
public:
stack(int tsize=0)
{
	if(tsize>0)
	{
		arr= new char[tsize];
		size=0;
		capacity=tsize;
		top=-1;
	}else
	{
		arr=nullptr;
		top=-1;
		size=capacity=0;
	}
}
stack(const stack& obj)
{
	 capacity=obj.capacity;
	 this->arr=new char [this->capacity];
	 size=obj.size;
	 top=obj.top;
	 for(int i=0;i<capacity;i++)
	 {
		 arr[i]=obj.arr[i];
	 }
}
const stack& operator= (const stack& obj)
{
	capacity=obj.capacity;
	 this->arr=new char [this->capacity];
	 size=obj.size;
	 top=obj.top;
	 for(int i=0;i<capacity;i++)
	 {
		 arr[i]=obj.arr[i];
	 }
	 return *this;
}
void push (char a)
{
	if(size<capacity)
	{
		arr[++top]=a;
		size++;
	}else if(capacity==0)
	{
		arr = new char[1];
		arr[0]=a;
		top=0;size=1;capacity=1;
	}else
	{
		char* temp= new char [2*capacity];
		for(int i=0;i<size;i++)
		{
			temp[i]=arr[i];
		}
		capacity*=2;size++;
		temp[++top]=a;
		delete [] arr;
		arr=temp;
	}
}
char pop()
{
	if(Isempty())
	{
		return '\0';
	}
	return arr[top];
	--top;
}
char Top()
{
	return arr[top];
}
//int Size()
//{
//	return size;
//}
void operator [](int x)
{
	arr= new char[x];
		size=0;
		capacity=x;
		top=-1;
}
//void Stack_array(char* a)
//{
//	for(int i=0;i<size;i++)
//	{
//		a[i]=arr[i];
//	}
//}
bool Isempty()
{
	return (size==0);
}
bool Isfull()
{
	return (size==capacity-1);
}
~stack()
{
	delete [] arr;
}
};
int main()
{

	
	system("pause");
	return 0;
}