#include<iostream>
#include<vector>
using namespace std;

class member
{
	struct treeNode{
		int YOfmembership;
		char DOB[10];
		char CNIC[13];
		treeNode * left, *right;

		treeNode(const int& year){
			YOfmembership=year;
			left=right=nullptr;
		}
	};
treeNode* root;
int n;
	void printInOrder(treeNode* curr)
	{
		if(curr!=nullptr)
		{
			printInOrder(curr->left);
			cout<<"YOfmembership: "<<curr->YOfmembership<<"\nDOB: ";cout<<curr->DOB<<"\nCNIC:"<<curr->CNIC;
			cout<<"\n**************************************\n";
			printInOrder(curr->right);
		}
	}
	void deleteMini(treeNode* curr)
	{
		if(curr!=nullptr)
		{
			deleteMini(curr->left);
			deleteMini(curr->right);
			delete curr;
		}
	}
	int numOfChild(treeNode* curr){
		if(curr==nullptr)
			return -1;
		else
			return 
			int(curr->left!=nullptr)+ int(curr->right!=nullptr);
	}
	void eraseCase0(treeNode* curr, treeNode* par)
	{
		if(curr==root)
		{
			root=nullptr;
		}else{
			if(curr==par->left)
				par->left=nullptr;
			else 
				par->right=nullptr;
		}
		delete curr;	
	}

	void eraseCase1(treeNode* curr, treeNode* par){
		if(curr==root){
			root = (curr->left!=nullptr)?curr->left:curr->right;
		}else{
			if(curr==par->left){
				par->left=(curr->left!=nullptr)?curr->left:curr->right;
			}else{
				par->right=(curr->left!=nullptr)?curr->left:curr->right;
			}
		}

		delete curr;	
	}
	void eraseCase2(treeNode* curr, treeNode* par)
	{


	}

public:
	member(){
		root=nullptr;
		n=0;
	}

	void eraseByYearOfMembership(const int& Y)
	{
		treeNode* par;
			treeNode*curr = (root->YOfmembership <Y)?par->right:par->left;
				
			if(numOfChild(curr)==0)
			{
				eraseCase0(curr, par);
			}else if(numOfChild(curr)==1)
			{
				//case 1
				eraseCase1(curr, par);
			}else
			{
				//case 2
				eraseCase2(curr, par);
			}

	}
	void insert(const int & YOfmember)
	{
		treeNode* par=root;
			treeNode * temp = new treeNode(YOfmember );// create function
			if(par==nullptr){//tree is empty
				root=temp;
			}else
			{
				
			}
			n++;
	}
	void Print()
	{
		printInOrder(root);
	}
	~member()
	{
		deleteMini(root);
	}
};
class DS
{


public:

};
int main()
{

}
