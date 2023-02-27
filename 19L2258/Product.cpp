#include<iostream>
using namespace std;
// A C++ Program to find the product of five natural numbers starting from a given integer

int MyProduct(int input)
{
	int iteration=0, product=1;
	while(iteration<5)		//run the loop for 5 times
	{
		product= product*input;
		input++;
		iteration++;
	}
	return product;
}



int main()
{
	int num=1;
	int result=1;
	cout<<"Enter the starting integer:";
	cin>>num;
	result=MyProduct(num);

	cout<<"The product of five natural numbers is: "<<result<<endl;

	system("pause");
	return 0;
}

/* When we put a breakpoint on function call, the statement above function call execute without any obstacle and 
compiler waits for stream insertion, that is input from user and when we input then compiler 
reaches on breakpoint and stop execution, now when we step over or step into, then compiler moves 
one by one statements and execute them. When the compiler comes from the breakpoint that is from the function call
line, then compiler executes rest of instruction without any hurdle

Now, when we put breakpoint at steam insertion and stream extration, the compiler stops 
at the breakpoints and waits for
our order of step into or step over, then get input and then stop again at other breakpoints
and executes from rest of the program without any hurdle.*/
