#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
class bst
{
	struct treeNode
	{
		T data;
		int h;       //height;
		treeNode* leftchild, * rightchild;
		treeNode(const T& obj, int h)
		{
			data = obj;//deep copy
			this->h = h;
			leftchild = rightchild = nullptr;
		}

	};
	treeNode* root;
	int n;
	bool getAccess(const T& key, treeNode*& par)
	{
		//returns false if key exists
		par = nullptr;
		treeNode* curr = root;
		while (curr != nullptr)
		{

			if (key == curr->data)
				return true;
			else
			{
				par = curr;
			}
			if (key < curr->data)
			{
				curr = curr->leftchild;
			}
			else
			{
				curr = curr->rightchild;
			}
		}
		return false;
	}
	bool rr(treeNode* ptr, treeNode* pptr)
	{
		//right rotate around ptr
		treeNode* cptr = ptr->leftchild;

		if (cptr == NULL)
			return false;
		else
		{
			//what is the node itself is the root
			//promote cptr
			if (pptr == nullptr)
			{
				root = cptr;
			}
			else
			{
				if (ptr == pptr->leftchild)
					pptr->leftchild = cptr;
				else
					pptr->rightchild = cptr;
			}
			//adjust children
			treeNode* rc_cptr = cptr->rightchild;
			cptr->rightchild = ptr;
			ptr->leftchild = rc_cptr;
			return true;
		}
	}
	bool rl(treeNode* ptr, treeNode* pptr)
	{
		//left rotate around ptr

		treeNode* cptr = ptr->rightchild;

		if (cptr == nullptr)
			return false;
		else
		{
			if (pptr == nullptr)
			{
				root = cptr;
			}
			else
			{
				if (ptr == pptr->leftchild)
					pptr->leftchild = cptr;
				else
					pptr->rightchild = cptr;
			}
			treeNode* lc_cptr = cptr->leftchild;
			cptr->leftchild = ptr;
			ptr->rightchild = lc_cptr;
			return true;
		}
	}
	bool getAccess(const T& key, treeNode*& curr, stack<treeNode*>& ancestors)
	{
		//ancestors.clear();

		/*
			>If tree is empty: ancestors stack is empty, and curr==nullptr
			>If curr is at root: acnestors stack is emptu, and curr==root
			>If curr is elsewhere is the tree,
			   ancestors stack contains ancestor pointers
			   curr is pointing to that node
			>If tree is not empty but curr does not exit: curr==nullptr,
			ancestors stack contains ancestor pointers
*/
		curr = root;
		if (curr == nullptr)
			return false;

		if (key == root->data)
			return true;

		while (curr != nullptr)
		{

			if (key == curr->data)
				return true;
			else
			{
				ancestors.push(curr);
			}
			if (key < curr->data)
			{
				curr = curr->leftchild;
			}
			else
			{
				curr = curr->rightchild;
			}
		}
		return false;
	}
	void printInOrder(treeNode* curr)
	{
		if (curr != nullptr)
		{
			//LNR
			printInOrder(curr->leftchild);
			cout << (curr->data) << " -> ";
			printInOrder(curr->rightchild);
		}
	}
	void printPostOrder(treeNode* curr)
	{
		if (curr != nullptr)
		{
			//LRN
			printPostOrder(curr->leftchild);
			printPostOrder(curr->rightchild);
			cout << (curr->data) << " ";
		}
	}
	void cleanup(treeNode* curr)
	{
		if (curr != nullptr) {//post order
			cleanup(curr->leftchild);
			cleanup(curr->rightchild);
			delete curr;
		}
	}
	void copy(treeNode*& curr, treeNode* objptr)
	{
		//Using Pre-order
		if (objptr != nullptr)
		{
			curr = new treeNode(objptr->data);
			copy(curr->leftchild, objptr->leftchild);
			copy(curr->rightchild, objptr->rightchild);
		}
	}
	int height(treeNode* ptr)
	{
		if (ptr == nullptr)
		{
			return -1;
		}
		else
		{
			return (1 + max(height(ptr->leftchild), height(ptr->rightchild)));
		}
	}
	int balancefact(treeNode* N)
	{
		if (N == NULL)
			return 0;
		return height(N->leftchild) - height(N->rightchild);
	}
	bool isBalanced(treeNode* ptr)
	{
		int bf = 0;
		if (ptr != nullptr)
		{
			isBalanced(ptr->leftchild);    //post order traversal LRN
			isBalanced(ptr->rightchild);
			bf = balancefact(ptr);
			if (bf != 0 && bf != 1 && bf != -1)
			{
				return false;
			}
		}
		return true;
	}
	int numOfChild(treeNode* curr)
	{
		if (curr == nullptr)
			return -1;
		else
			return
			int(curr->leftchild != nullptr) +
			int(curr->rightchild != nullptr);
	}
	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}
	treeNode* rightRotate(treeNode* y)
	{
		treeNode* x = y->leftchild;
		treeNode* T2 = x->rightchild;
		x->rightchild = y;
		y->leftchild = T2;
		y->h = max(height(y->leftchild),height(y->rightchild)) + 1;
		x->h = max(height(x->leftchild),height(x->rightchild)) + 1;
		return x;
	}
	treeNode* leftRotate(treeNode* x)
	{
		treeNode* y = x->rightchild;
		treeNode* T2 = y->leftchild;
		y->leftchild = x;
		x->rightchild = T2;
		x->h = max(height(x->leftchild),height(x->rightchild)) + 1;
		y->h = max(height(y->leftchild),height(y->rightchild)) + 1;
		return y;
	}
	treeNode* SmallestNode(treeNode* node)
	{
		treeNode* current = node;
		while (current->leftchild != NULL)
			current = current->leftchild;
		return current;
	}
public:
	bst(const bst<T>& obj)
	{
		//copy constructor
		copy(root, obj.root);
	}
	const bst<T>& operator = (const bst<T>& obj)
	{
		cleanup(root);//uses post order
		copy(root, obj.root);//uses preorder
	}
	void insert(const T& data)
	{
		treeNode* par;
		stack<treeNode*> ancestors;
		treeNode* curr;
		getAccess(data, curr, ancestors);
		if (getAccess(data, par) == false)
		{
			//add new node as a child of parent
			//par contains the parent pointer
			treeNode* temp = new treeNode(data, height(root) + 1);
			if (par == nullptr)
			{//tree is empty
				root = temp;
			}
			else
			{
				if (par->data < data)
				{
					par->rightchild = temp;
				}
				else
				{
					par->leftchild = temp;
				}
			}
			n++;
		}
		if (isBalanced(root) == false)
		{
			treeNode* pptr = ancestors.top();
			if (balancefact(pptr) > 1 || balancefact(pptr) < -1)
			{

				treeNode* panc = ancestors.empty() ? nullptr : ancestors.top();

				if (balancefact(pptr) == 2 && balancefact(pptr->rightchild) == 1)
				{
					//right-right
					rl(pptr, panc);
				}
				else if (balancefact(pptr) == -2 && balancefact(pptr->leftchild) == -1)
				{
					//left-left
					rr(pptr, panc);
				}
				else if (balancefact(pptr) == 2 && balancefact(pptr->rightchild) == -1)
				{
					//right-left
					rr(pptr->rightchild, pptr);//make it a right-right imbalance
					rl(pptr, panc);
				}
				else if (balancefact(pptr) == -2 && balancefact(pptr->leftchild) == 1)
				{
					//left-right
					rl(pptr->leftchild, pptr);//make it a left-left imbalance
					rr(pptr, panc);
				}
			}
		}
	}
	void printInOrder()
	{
		printInOrder(root);
		cout << "nullptr\n";
	}
	bool isBalance()
	{
		return isBalance(root);
	}
	treeNode* Erase_mini(treeNode* root, T key)
	{
		if (root == NULL)
			return root;
		if (key < root->data)
			root->leftchild = Erase_mini(root->leftchild, key);
		else if (key > root->data)
			root->rightchild = Erase_mini(root->rightchild, key);
		else
		{
			if ((root->leftchild == NULL) ||	(root->rightchild == NULL))
			{
				treeNode* temp = root->leftchild ?
					root->leftchild :
					root->rightchild;
				if (temp == NULL)	// No child case
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;		// One child case
				free(temp);
			}
			else
			{
				treeNode* temp = SmallestNode(root->rightchild);		// node with two children
				root->data = temp->data;
				root->rightchild = Erase_mini(root->rightchild,temp->data);
			}
		}
		if (root == NULL)
			return root;
		/////////////////////////////////////////////////////
		root->h = 1 + max(height(root->leftchild),height(root->rightchild));
		/////////////////////////////////////////////////////
		int balance = balancefact(root);
		if (balance > 1 && balancefact(root->leftchild) >= 0)
			return rightRotate(root);
		if (balance > 1 && balancefact(root->leftchild) < 0)
		{
			root->leftchild = leftRotate(root->leftchild);
			return rightRotate(root);
		}
		if (balance < -1 && balancefact(root->rightchild) <= 0)
			return leftRotate(root);
		if (balance < -1 && balancefact(root->rightchild) > 0)
		{
			root->rightchild = rightRotate(root->rightchild);
			return leftRotate(root);
		}
		return root;
	}
	void Erase(T key)
	{
		this->root = Erase_mini(root,key);
	}
	bst()
	{
		root = nullptr;
		n = 0;
	}
	~bst()
	{
		cleanup(root);
	}
};

int main()
{
	bst<int> t1;
	t1.insert(8);  t1.insert(1); t1.insert(0);
	t1.insert(10); t1.insert(6);	t1.insert(2);
	t1.insert(7); t1.insert(11); t1.insert(18);
	t1.printInOrder();
	t1.Erase(10);
	t1.Erase(6);
	t1.printInOrder();
	return 0;
}
