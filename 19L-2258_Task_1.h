#pragma once
#include<iostream>
using namespace std;
//###################################################################################
template <class T>
class Node
{
public:
	T data;
	Node<T> * next;
	Node<T> * prev;
};
//###################################################################################
template<class T>
class DoublyLinkedList
{
	Node<T> * head;
	Node<T> * tail;
public:
	DoublyLinkedList();				//•	Default Constructor
	DoublyLinkedList(const DoublyLinkedList & obj)
	{
	if (obj.head != NULL)
	{
		Node<T> *head = new Node<T>;
		head = obj.head;
		
		Node<T> *current = head;

		Node<T> *objcurrent = obj.head->next;
		while (objcurrent!=NULL)
		{
			Node<T> *newNode = new Node<T>;
			newNode = objcurrent;
			current->next = newNode;

			objcurrent = objcurrent->next;
		}
		Node<T> *t = new Node<T>;
		t = obj.tail;
	}
}
	void insertAtStart(T const a);	//•	Insert at start:
	void insertAtEnd(T const a);	//•	Insert at start:
	void DeleteAtStart();			//•	Delete from Start :
	void DeleteAtEnd();  			//•	Delete from end :
	void ReversePrint();			//•	Reverse print all elements of linked list :
	void print();					//•	Print: 
	bool insertBefore(T const b, T const c);	//•	Insert value v1 before value v2: 
	~DoublyLinkedList();
};
//###################################################################################
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	
}
//###################################################################################
template<class T>
void DoublyLinkedList<T>::insertAtStart(T const data)
{
	Node<T> * newNode = new Node<T>;
	if (head==NULL)
	{
		
		head = newNode;
		tail = newNode;

		head->data = data;
		head->prev = NULL;
		head->next = NULL;

		tail->data = data;
		tail->prev = NULL;
		tail->next = NULL;
	}
	else
	{
		Node<T>* tempNode = head;
		head = newNode;
		head->data = data;
		head->prev = NULL;
		head->next = tempNode;
		tempNode->prev = head;
	}
}
//###################################################################################
template<class T>
void DoublyLinkedList<T>::insertAtEnd(T const data)
{
	Node<T> * newNode = new Node<T>;
	if (head==NULL)
	{
		
		head = newNode;
		tail = newNode;

		head->data = data;
		head->prev = NULL;
		head->next = NULL;

		tail->data = data;
		tail->prev = NULL;
		tail->next = NULL;
	}
	else
	{
		Node<T>* tempNode = tail;
		tail = newNode;
		tail->data = data;
		tail->prev = tempNode;
		tail->next = NULL;
		tempNode->next = tail;
	}
}
//###################################################################################
template<class T>
void DoublyLinkedList<T>::print()
{
	if (head == NULL)
		cout << "List is empty!";
	else
	{
		Node<T>* current = head;
		while (current != NULL)
		{
			cout << current->data << "  ";
			current = current->next;
		}
		cout << endl;
	}
}
//###################################################################################
template<class T>
bool DoublyLinkedList<T>::insertBefore(T const v1, T const v2)
{
	int B = 0;
	Node<T> *current = head;
	while (current != NULL)
	{
		if (current->data == v2)
		{
			B = 1;
			break;
		}
		current = current->next;
	}
	if (B == 1)
	{	
		Node<T> *nptr = new Node<T>;
		nptr->data = v1;
		nptr->next = current;
		nptr->prev = current->prev;
		head->next = nptr;
		return true;
	}
	else
		return false;
}
//###################################################################################
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	delete head;
	head = nullptr;
	delete tail;
	tail = nullptr;
}
//###################################################################################
template <class T>
void DoublyLinkedList<T>::ReversePrint()
{
	Node<T> *current = tail;
	do
	{
		cout << current->data << "   ";
		current = current->prev;
		
	} while (current != NULL);
	cout<<endl;
}
//###################################################################################