#include<iostream>
using namespace std;
int SumOfDigit(int n)
{
    if (n==0)
		return 0;
    return (n%10 + SumOfDigit(n/10));
}
int main()
{
    int no = 123;
    int res = SumOfDigit(no);
    cout << "Sum of Digits in "<< no <<" = "<<res << endl;
	system("pause");
    return 0;
}