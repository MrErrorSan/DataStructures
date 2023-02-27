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
void pop()
{
	if(Isempty())
	{
		return;
	}
	--top;
}
char Top()
{
	return arr[top];
}
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
void advanceReverse(char str[])
	{
		int count=0;
		for(int i=0;str[i]!='\0';i++)
		{
			for(;str[count]==' '||str[count]=='\0';count++);
			
				stack R(count);
				for(int a1=i;a1<count+i;a1++)
				{
					R.push(str[a1]);
				}
				for(;i<count+i;i++)
				{
					str[i]=R.Top();
					R.pop();
				}
				count++;	
		}
	}
int main()
{
	char A[15]="1234 abcd !@#$";
	cout<<A<<endl;
	advanceReverse(A);
	cout<<A<<endl;

	
	system("pause");
	return 0;
}