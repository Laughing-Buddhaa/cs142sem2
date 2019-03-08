#include<iostream>
using namespace std;

class node		//node class 
{
public:
	int data;   //components
	node *left;
	node *right;	
	
	node(int value)  //constuctor
	{
		left = NULL;
		right = NULL;
		data = value;
	}
};

class binary
{
public:
	
	node *root;
	binary()		//default constuctor
	{
		root =  NULL;		
	}
	
	void insert(int value)		//insert function
	{
		insert1(root,value);	//mechanism to bypass root call restrictions
	}
	
	void insert1(node *curr,int value)		//insert helper function
	{
		if(curr == NULL) 		//base condition
		{
			curr = new node(value);
			if(root == NULL) root = curr;
		}
		
		else if(curr->data<value)	//move  left or right 
		{
			if(curr->right==NULL) curr->right = new node(value);
			insert1(curr->right, value);
		}
		else
		{
			if(curr->left==NULL) curr->left = new node(value);
			insert1(curr->left,value);
		}	
	}
	
	void display()
	{
		display1(root);	
	}
	
	void display1(node *curr)
	{
		if(curr==NULL) return;  //base condition
		else
		{
			display1(curr->left);	//inorder 
			cout<<curr->data<<",";
			display1(curr->right);
		}
	}
	
	node* search(int value)
	{
		research(root,value);
	}
	
	node* research(node *curr,int value)
	{
		if(curr==NULL || curr->data==value) return curr; //base condition
		if(curr->data<value) return research(curr->right,value); //move left or right
		else return research(curr->left,value); 
	}
};
int main()  //driver function
{
	binary b;
	b.insert(3);
	b.insert(2);
	b.insert(4);
	b.display();
	cout<<endl;
	cout<<b.search(4);
	return 0;
}

//how to check whether search function is working fine?
