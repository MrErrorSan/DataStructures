//   \\cactus\Xeon\Spring 2021\Data Structures Lab\Final's Submission\4F
#include<iostream>
using namespace std;

class Node {
private:
	int key;
	int value;
	Node*next;
public:
	Node(int val_key, int val_data)
	{
		key = val_key;
		value = val_data;
		next = nullptr;
	}
	void setKey(int val_key)
	{
		key = val_key;
	}
	void setValue(int val_data)
	{
		value = val_data;
	}
	void setNext(Node* node)
	{
		next = node;
	}
	int getKey()
	{
		return key;
	}
	int getValue()
	{
		return value;
	}
	Node* getNext()
	{
		return next;
	}

};
class LinkedList {
private:
	Node* head;
public:
	LinkedList() // Default constructor
	{
		head = nullptr;
	}
	~LinkedList()// Destructor
	{
		Node* current = head;
		Node* next;

		while (current != nullptr) {
			next = current->getNext();
			delete current;
			current = next;
		}
		head = nullptr;
	}
	bool insert(int val_key, int val_data)
	{
		Node* new_node = new Node(val_key, val_data);
		if (head == nullptr)
		{
			head = new Node(val_key, val_data);
			return true;
		}
		Node *last = head;
		while (last->getNext() != nullptr)
			last = last->getNext();
		last->setNext(new_node);
		return true;
	}
	void display()
	{
		Node*tnode = head;
		while (tnode != nullptr)
		{
			cout << "<" << tnode->getKey() << "," << tnode->getValue() << ">" << " ";
			tnode = tnode->getNext();
		}
	}
	bool deleteNthNode(int val)
	{
		// Store head node
		Node* temp = head;
		Node* prev = NULL;

		if (temp != NULL && temp->getKey() == val)
		{
			head = temp->getNext();
			delete temp;
			return true;
		}
		else
		{
			while (temp != NULL && temp->getKey() != val)
			{
				prev = temp;
				temp = temp->getNext();
			}

			if (temp == NULL)
				return false;

			prev->setNext(temp->getNext());
			delete temp;
			return true;
		}
	}
	bool search(int val)		//searching Key
	{
		Node* current = head; // Initialize current
		while (current != nullptr)
		{
			if (current->getKey() == val)
				return true;
			current = current->getNext();
		}
		return false;
	}
	Node* getHead()
	{
		return head;
	}
	////////////////////////////////////////////////////
	LinkedList& splitList(const LinkedList& l1, int x)
	{
		LinkedList R;
		if(!search(x))
		{
			cerr<<"\nWrong Key Value....."<<endl;
			return R;
		}
		Node* curr = l1.head;//copying head in curr
		while(curr!=nullptr)// adding all nodes less than given key's node in order
		{
			if(curr->getKey() < x)
			{
				R.insert(curr->getKey(),curr->getValue());
			}
			curr=curr->getNext();
		}
		curr = l1.head;
		while(curr!=nullptr)// adding key's node
		{
			if(curr->getKey() == x)
			{
				R.insert(curr->getKey(),curr->getValue());
			}
			curr=curr->getNext();
		}
		curr = l1.head;
		while(curr!=nullptr)// adding all nodes greater than given key's node in order
		{
			if(curr->getKey() > x)
			{
				R.insert(curr->getKey(),curr->getValue());
			}
			curr=curr->getNext();
		}
		return R;
	}
};
int main()
{
	LinkedList T;
	T.insert(2,12);
	T.insert(9,23);
	T.insert(67,2);
	T.insert(4,3);
	T.insert(6,1);
	T.insert(1,21);
	T.insert(3,9);
	T.insert(12,90);
	T.display();
	T.splitList(T,4);
	system("pause");
	return 0;
}
