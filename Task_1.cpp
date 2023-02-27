#include<iostream>
using namespace std;
int Search(int arr[], int index,int size, int x)
{
    if (size < index)
        return -1;
    if (arr[index] == x)
        return 0;
    return Search(arr,index+1,size-1,x);
}
int main()
{
	int arr[] = {0,1,3,4,5,6,7,8,9};
    int n = 10; int integer = 5;
    int check = Search(arr,0,n-1,integer);
    if (check != -1)
	{
		cout << "Element "<<integer<<" is present"<<endl;
	}
    else
	{
		cout << "Element "<<integer<<" is not present" <<endl;
	}
	system("pause");
	return 0;
}