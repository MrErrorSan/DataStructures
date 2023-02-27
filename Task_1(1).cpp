#include"STACK.h"
#include<iostream>
using namespace std;
int whatChar (char a)
	{
			if(a=='+')
			{return 1;
			}else if(a=='-')
			{return 2;
			}else if(a=='*')
			{return 3;
			}else if(a=='/')
			{return 4;
			}else if(a=='=')
			{return 5;
			}else
			{return 0;
			}
	}
int postfix(stack<int>& S,char str[])
{
	int i=0,op1=0,op2=0;
	for(;whatChar(str[i])!=5;i++)
	{
		for(;whatChar(str[i])==0;i++)
		{
			S.Push((int)str[i]-48);
			//cout<<S.Peek()<<endl;
		}

		if(S.Peek()==NULL)
			return -1;// if invalid output is -1
		else {
		op2=S.Peek();
		S.Pop();
		}
		if(S.Peek()==NULL)
			return -1;// if invalid output is -1
		else{
		op1=S.Peek();
		S.Pop();
		}
		for(;whatChar(str[i])!=0&&whatChar(str[i])!=5;i++)
		{
			if(whatChar(str[i])==1)
			{
				S.Push(op1+op2);	
			}else if (whatChar(str[i])==2)
			{
			S.Push(op2-op1);
			}else if (whatChar(str[i])==3)
			{
				S.Push(op1*op2);
			}else if (whatChar(str[i])==4)
			{
				S.Push(op2/op1);
			}

			if(whatChar(str[i+1])!=5 && whatChar(str[i+1])!=0)
			{
				op2=S.Peek();
				S.Pop();
				op1=S.Peek();
				S.Pop();
			}
		}
		if(whatChar(str[i])==5)
		{
			if(S.Peek()!=NULL)
			return S.Peek();
			else 
			return -1;// if invalid output is -1
		}
	}

	return -1;// if invalid output is -1
}
int main()
{
	stack<int> s;
	char a[]="63+2*=";
	int x=postfix(s,a);
	cout<<x<<endl;
	system("pause");
	return 0;
}