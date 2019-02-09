#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node()
	{
		next =  NULL;
	}
};

 class l{
 	public:
 	node *head;
 	l()
 	{
 		head = NULL;
 	}
	
	void insert(int value)
	{
		node *current = head;
		node *temp = new node;
		temp->data = value;
		if(head == NULL)
		{
			head = temp;
		}
		else
		{
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = temp;
		}
	}
	
	int count()
	{
		int n=1;
		node *current = head;
		while(current->next != NULL)
		{
			n++;
			current = current->next;
		}
		return n;
	}
	void disp()
	{
		int n = count();
		int i=0;
		node *current = head;
		while(i<n)
		{
			cout<<current->data<<"->";
			current= current->next;
			i++;
			
		}
	}
	
	void insertat(int value,int i)
	{
		int n= count();
		int j=1;
		node *temp = new node;
		node *current =head;
		if(i<0 && i>n)
		{
			cout<<"the given postion doesn't exist";
		}
		else if(head == NULL)
		{
			
			head = temp;
			temp->data = value;
		}
		else
		{
			
		
		while(j<i)
		{
			current= current->next;
			j++;	
		}
			temp->next = current->next ;
			temp->data = value;
			current-> next = temp;
		}
	}
	void del()
	{
		node *current = head;
		
		while(current->next->next != NULL)
		{
			current = current->next;	
		}		
		node *temp = current->next;
		current->next = NULL;
		delete temp;
	}
	
	void delat(int pos)
	{
		node *current = head;
		node *temp = head;
		int i=0;
		if(i<0 && i>pos)
		{
			cout<<"Enter proper position";
		}
		else
		{
			while(i<pos-1)
			{
				current = current->next;
				i++;
			}
			while(i<pos)
			{
				temp = temp->next;
				i++;
			}
			current->next = temp->next;
			delete temp;
		}
	}
 };
 class slack
 {
 	public:
 	node *top;
 	slack()
	{
		top = NULL;
	}
	
	l l1;
	void push(int value)
	{	
		l1.insert(value);			
	}	
	
	void pop()
	{
	}
	
	int size()
	{
		int n = l1.count();
		return n;
	}
	
	bool isEmpty()
	{
		if(top == NULL) return true;
		return false;
	}
	
	void topdisplay()
	{
		top = l1.head;
		cout<<top;
	}
 };
int main()
{
	l l2;
	for(int i=0;i<5;i++)
	{
		l2.insert(i+1);	
	}
	l2.disp();
	cout<<endl;
	l2.insertat(6,2);
	l2.disp();
	cout<<endl;
	l2.delat(2);
	l2.disp();
	return 0;
}

