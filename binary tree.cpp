/*
what is a tree?
node without parent is called root
node without any children is called leaf
everything in between is called intermediate
if every node has max of 2 children it's called binary tree
every link is called edge
the set of link connecting any two node is called path
height is the minimum no of links from root to farthest leaf
balanced tree always has least possible height
each point of branching is called a level
the rule of binary tree is left is alwaays less than right

how to insert?
first check if root is empty if so root == new node
else using recursion move left/right depending upon value of new node 
stopping condition is you reach a leaf i.e. curr == NULL

how to search?
at each point search your value with the data of node and acoordingly direct 
left or right
return if it's NULL
*/
#include<iostream>
using namespace std;
class node
{
	public:
	//bache mere bache 
	int data;
	node *left;
	node *right;
	node *parent;
	//default constructor
	node(int val)
	{
		data = val;
		left= NULL;
		right = NULL;
		parent=NULL;	
	}
	
};

class bst
{
public:
	node *root;
	
	bst()
	{
		root = NULL;
	}
	
	void inserthelper(node *curr,int val)
	{
		if(curr == NULL)
		{
			curr = new node(val);
			if(root == NULL) root = curr;
			return ;
		}	
		else if(val < curr->data)
		{
			if(curr->left == NULL) { curr->left = new node(val);
			curr->left->parent = curr; }
			else inserthelper(curr->left,val);
		}
		else
		{
			if(curr->right == NULL) { curr->right = new node(val);
			curr->right->parent = curr; }
			else inserthelper(curr->right,val);
		}
	}
	
	void insert(int val)
	{
		inserthelper(root,val);
	}
	
	void display()
	{
		display2(root);
	}
	void display2(node *curr)
	{
	//base condition
		if(curr == NULL) return ;
	//display left
		display2(curr->left);
	//display current
		cout<<curr->data<<",";
	//display right
	 	display2(curr->right);
	}
	
	node* search(int val)
	{
		return research(root,val);
	}
	
	node* research(node *curr, int val)
	{
		//if you reach end or find it
		if(curr == NULL || curr->data == val) return curr;
		else if(curr->data <val) return research(curr->left,val);
		else return research (curr->right,val);
		
		
	}
	
	node* findmin(node *curr)
	{
		if(curr == NULL) return curr;
		else if(curr->left==NULL) return curr;
		else   findmin(curr->left);
	}
	
	node* findmax(node *curr)
	{
		if(curr== NULL) return curr;
		else if(curr->right == NULL) return curr;
		else findmax(curr->right);
	}
	
	int count(node *curr,int i)
	{
		if(curr==NULL) return i;
		else 
		{
			i++;
			count(curr->left,i);
			count(curr->right,i);
		}
	}
	/*void replace(node *curr,node *temp)
	{
		if(curr->parent->left == curr) curr->parent->left = temp;
		else curr->parent->right = temp;
	}*/
	void dataswap(node *curr,node *temp)
	{
		int k = temp->data;
		temp->data = curr->data;
		curr->data = k;
	}
		
	void deletenode(int data)
	{
		node *curr = search(data);
		if(curr->right != NULL && curr->left != NULL)
		{
			node *temp = findmin(curr->right);
			dataswap(curr,temp);
			delete temp;
		}
		else if(curr->right == NULL && curr->left == NULL)
		{
			delete curr;
		}
		else
		{
			if(curr->right!=NULL)
			{
				node *temp = findmin(curr->right);
				dataswap(curr,temp);
				delete temp;
			}
			else
			{
				node *temp= findmax(curr->left);
				dataswap(curr,temp);
				delete temp;
			}
		}
	}				
	};

int main()
{
	bst b;
	b.insert(100);
	b.insert(70);
	b.insert(120);
	b.display();
	cout<<endl;
	/*cout<<b.findmin(b.search(4))->data;*/
	cout<<b.count(b.search(3),1);
	return 0;
}
