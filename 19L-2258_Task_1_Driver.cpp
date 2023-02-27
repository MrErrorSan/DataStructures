#include"19L-2258_Task_1.h"
int main()
{
	const int a = 7,b = 9, c = 11,d = 6, e = 2 , f=7;
	DoublyLinkedList<int> obj;
	obj.insertAtEnd(a);
	obj.insertAtEnd(b);
	obj.insertAtStart(c);
	obj.insertBefore(d,f);
	obj.insertAtEnd(d);
	obj.insertAtEnd(e);
	obj.print();
	obj.ReversePrint();
	//obj.print();
	system("pause");
	return 0;
}