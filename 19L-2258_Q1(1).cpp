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
class Queue
{
private:
	stack stack1,stack2;
	int siz;
	int sizeStack1,sizeStack2;
public:
Queue(int s=0)
	{
		if(s>0)
		{
			stack1[s];stack2[s];
			siz=0;sizeStack1=0,sizeStack2=0;
		}else{
			siz=0;sizeStack1=0,sizeStack2=0;
			stack1[0];stack2[0];
		}
	}
void enQueue(char x)
{
	stack1.push(x);
	siz++;sizeStack1++;
}
char deQueue()
{
//If stack2 is empty and stack1 is not empty
//Copy all data from stack1 to stack2
	if(sizeStack2==0)
	{
	for(int i=0;i<sizeStack1;i++)
		{
			stack2.push(stack1.Top());
		}
	sizeStack2=sizeStack1;
	siz=0;sizeStack1=0;
		return stack2.pop();
		siz--;sizeStack2--;
	}
//Else if stack2 is not empty
	else if(sizeStack2!=0){
			return stack2.pop();
			siz--;sizeStack2--;
	}
//Else
//“UnderFlow”
	else
	{
		return '\0';
	}

}
int size()
{
	return (sizeStack1 + sizeStack2);
}
bool isEmpty()
{
//Return (stack1 is empty and stack2 is empty)
	if(stack1.Isempty() && stack2.Isempty())
		return true;
	else
		return false;
}
void display()
{
	if(sizeStack2!=0)
	{
	stack A2(stack2);
	for(int i=0;i<sizeStack2;i++)
	cout<<A2.pop();
	}
	if(sizeStack1!=0)
	{
	char* arr=new char [sizeStack1];
	stack A1(stack1);
	for(int i=0;i<sizeStack2;i++)
	{
		arr[i]=A1.pop();
	}
	for(int i=sizeStack1;i>0;i--)
		cout<<arr[i];
	}
}
~Queue()
{
	stack1.~stack();
	stack2.~stack();
}
};
int main()
{

	
	system("pause");
	return 0;
}