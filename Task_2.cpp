#include<iostream>
using namespace std;
int FibonacciNo(int a)
{
    if (a <= 1)
        return a;
    return FibonacciNo(a-1) + FibonacciNo(a-2);
}
int main ()
{
    int n = 6;
    cout << FibonacciNo(n) << endl;
	system("pause");
    return 0;
}