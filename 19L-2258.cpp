#include<iostream>
using namespace std;
////////////<< TASK#1 >>///////////////
int Search(int arr[], int index, int size, int x)
{
	if (size < index)
		return -1;
	if (arr[index] == x)
		return 0;
	return Search(arr, index + 1, size - 1, x);
}
int isMember(int arr[], int integer)
{
	int n = 10;
	return Search(arr, 0, n - 1, integer);
}
////////////<< TASK#2 >>///////////////
int FibonacciNo(int a)
{
	if (a <= 1)
		return a;
	return FibonacciNo(a - 1) + FibonacciNo(a - 2);
}
////////////<< TASK#3 >>///////////////
int sum_digit(int n)
{
	if (n == 0)
		return 0;
	return (n % 10 + sum_digit(n / 10));
}
////////////<< TASK#4 >>///////////////
void flip_float_array(float arr[], int size, int start, int end)
{
	float temp;
	if (size == 0)
		return;
	if (start == size / 2)
		return;
	temp = arr[start - 1];
	arr[start - 1] = arr[end - 1];
	arr[end - 1] = temp;

	flip_float_array(arr, size - 1, start + 1, end - 1);
}
int main()
{
	cout << "  << TASK#1 >>" << endl;
	int arr[] = { 0,1,3,4,5,6,7,8,9 };
	int integer = 5;
	int check = isMember(arr, integer);
	if (check != -1)
	{
		cout << "Element " << integer << " is present" << endl;
	}
	else
	{
		cout << "Element " << integer << " is not present" << endl;
	}
	cout << "\n  << TASK#2 >>" << endl;
	 int n = 6;
	cout << FibonacciNo(n) << endl;
	cout << "\n  << TASK#3 >>" << endl;
	int no = 123;
	int res = sum_digit(no);
	cout << "Sum of Digits in " << no << " = " << res << endl;
	cout << "\n  << TASK#4 >>" << endl;
	float arr1[] = { 3.9, 5.2, 6.6, 8.3, 1.1 };
	flip_float_array(arr1, 5, 1, 5);
	for (int i = 0; i < 5; i++)
		cout << arr1[i] << " ";
	cout << endl;
	//system("pause");
	return 0;
}