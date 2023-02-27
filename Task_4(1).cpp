#include <iostream>
using namespace std;
void SwapArray(float arr[], int size, int start , int end)
{
    float temp;
	if (start == size/2) 
        return;

	temp=arr[start+1];
	arr[start+1]=arr[end-1];
	arr[end-1]=temp;

    SwapArray(arr, size-1,start+1,end-1);
}
int main()
{ 
    float arr[] = { 3.9, 5.2, 6.6, 8.3, 1.1 };
    int n = 5;
	SwapArray(arr, n ,1,5);
    return 0;
}