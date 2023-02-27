#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Set
{
	struct bst
	{
		int value;
		bst *leftChild;
		bst *rightChild;
		bst(const int& data)
		{
			value=data;
			leftChild=rightChild=nullptr;
		}
	} 
	* root;
	bool getAccess(const int& key, bst*& par){
		//returns false if key exists
		par=nullptr;
		bst*curr = root;
		while(curr!=nullptr){
			par=curr;
			if(key==curr->value)
				return true;
			else if(key<curr->value){
				curr=curr->leftChild;
			}else{
				curr=curr->rightChild;
			}
		}
		return false;
	}
	void printInOrder(bst* curr){
		if(curr!=nullptr){
			//LNR
			printInOrder(curr->leftChild);
			cout<<(curr->value)<<" ";
			printInOrder(curr->rightChild);
		}
	}
	void cleanup(bst* curr){
		if(curr!=nullptr){//post order
			cleanup(curr->leftChild);
			cleanup(curr->rightChild);
			delete curr;
		}
	}
	void copy(bst*& curr, bst* objptr){
		//Using Pre-order
		if(objptr!=nullptr){
			curr = new bst(objptr->value);
			copy(curr->leftChild, objptr->leftChild);
			copy(curr->rightChild, objptr->rightChild);
		}
	}
public:
//Methods
void addElement(int x) /*insert element in the bst. No duplication allowed.*/
{
	bst* par;
		if(getAccess(x, par)==false){
			//add new node as a child of parent
			//par contains the parent pointer
			bst * temp = new bst(x);
			if(par==nullptr){//tree is empty
				root=temp;
			}else{
				if(par->value<x){
					par->rightChild=temp;
				}else{
					par->leftChild=temp;
				}
			}
		}
}
void printSet_Inorder()/*Print the bst using recursive inorder traversal*/
{
		printInOrder(root);
}
bool isMember(int x)
{
	return getAccess(x,this->root);
}
Set unionbst (const Set & obj) /*Perform set union on bst. Make sure no
duplication. The answer is returned as a third set. Note: copy constructor is needed.*/
/*constructors and destructor*/
{
	return obj;
}
Set intersectionbst (const Set & obj) /*Perform set intersection on bst . Make sure
no duplication. The answer is returned as a third set. Note: copy constructor is
needed.*/
{
	return obj;
}
/*constructors and destructor*/
Set() //set root to null
{
	root=nullptr;
}
Set(const Set & obj) //copy constructor
{
	copy(root, obj.root);
}
~Set() //clean up memory
{
	cleanup(root);
}
const Set& operator = (const Set& obj)
{
	cleanup(root);//uses post order
	copy(root, obj.root);//uses preorder
	return *this;
}
//implement Assignment Operator
};
int main()
{
Set s1;
s1.addElement(10);
s1.addElement(5);
s1.addElement(30);
Set s2;
s2.addElement(10);
s2.addElement(30);
s2.addElement(50);
s1.printSet_Inorder();cout<<endl; //prints 5 10 30
s2.printSet_Inorder ();cout<<endl; // prints 10 30 50
cout<< s1.isMember(4)<<endl;
cout<< s2.isMember(40)<<endl;
Set s3=s1.intersectionbst(s2);
s3.printSet_Inorder(); //prints 10 30
Set s4=s1.unionbst(s2);
s4.printSet_Inorder(); //prints 5 10 30 50
//Copy Constructor and Assignment Operator
Set s5 = s3;
s5.printSet_Inorder();
Set s6;
s6 = s4;
s6.printSet_Inorder();
system("pause");
return 0;
}