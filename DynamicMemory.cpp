#include <iostream>
using namespace std;
//Take input until user enters -1. Store input in an array of size 5. If array is filled, double the array size.

void output_array(int size, int* arr)
{
    int* lastelement = arr + (size - 1);

    for (int i = 0 ; i<size; i++)
        cout << *(arr+i) << ", ";
    cout << endl;
}

int main()
{
    int size = 5, input = 0, counter = 0;
    int* ptr = new int [size];
    
    while (input != -1) //Take input continuously untill user wants toi terminate
	{
        for (; counter < size ; counter++ )	//Keep filling array until its full
		{
            cout << "enter number: ";
            cin >> input;
            
            if (input == -1)
                break;
            else 
			{
                *(ptr + counter) = input;
            }
        }
        

        if (input != -1)
		{
            int* temp = new int [size];
            //copying contents of ptr to temp

			for (int i = 0; i <counter ; i++)
			{
                *(temp + i) = *(ptr+i);
            }

               
            delete [] ptr;
            //doubling size
            size *= 2;
            //declaring ptr with double size and copying back contents from temp
            /*int * */ptr = new int [size];
            int i=0;
			for (i = 0 ; i < size/2 ; i++)
			{
                * (ptr + i) = * (temp + i);
            }
			counter = i;
            delete [] temp;
        }
    }

    output_array (counter, ptr);
    return 0;
}

/* 
ptr was already declared, so no need to declare it again, it was creating troublc
removing it will romve the problem*/
