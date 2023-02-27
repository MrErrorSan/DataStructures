#include<iostream>
using namespace std;
int power(int num, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
	{
		int z =power(num, n / 2);
        return z*z;
	}
    else
        return num * power(num, n / 2) * power(num, n / 2);
}
int Recursive(int x,int n,int Current = 1,int sum = 0)
{
    int result=0;
    int p = power(Current,n);
    while (p+sum < x)
	{
        result += Recursive(x,n,Current+1,p+sum);
        Current++;
        p = power(Current, n);
    }
    if (p+sum == x)
        result++;
    return result;
}
int main()
{
    int x = 10, n = 2;
    cout << Recursive(x, n)<<endl;
	system("pause");
	return 0;
}