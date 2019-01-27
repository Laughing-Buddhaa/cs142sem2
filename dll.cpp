#include<iostream>
using namespace std;
class node
{
	public: 
	int data;
	node *next;
	
	node()
	{
		next = NULL;
	}
};
class l
{
	public: 
	node *head;
	
	l()
	{
		head = NULL;
	}
	
	void insert(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = head;
		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			node *current = head;
			while(current->next != head)
			{
				current = current->next;
			}
			current->next = temp;
		}	
		
	}
	int count()
	{
		int n=0;
		node *current ;
		current  = head;
		while(current->next != head)
		{
			n++;
			current = current->next;
		}
		return n+1;
	}
	 
	void insertat(int value, int pos)
	{
		int n= count();
		int i=1;
		if(pos>n)
		{
			cout<<"the given position does'nt exist ";
		}
		else
		{
			node *current = head;
			while(i<pos-1)
			{
				current = current->next;
			}
			node *temp;
			temp->data = value;
			temp->next = current->next;
			current->next = temp;
		}
	}
	 
	void del()
	{
	 	node *current =head;
	 	node *temp =head;
	 	while(temp->next != head)
		 	{
	 			temp= temp->next;
			}
		while(current->next->next != head)
	 	{
	 		current= current->next;	
		}
		current->next =head;
		delete temp;
	}
	
	void delat(int pos)
	{
		int n= count();
		int i=1,j=1;
		if(pos>n)
		{
			cout<<"the given position doesn't exist.";
		}
		else
		{
			node *c1 = head;
			node *c2 = head;
			while(i<pos-1)
			{
				i++;
				c1 = c1->next;
			}
			while(j<pos)
			{
				j++;
				c2=c2->next;
			}
			c1->next = c2->next;
			delete c2;
		}
	}
	
	void disp()
	{
		node *current = head;
		while(current->next != head)
		{
			cout<<current->data<<"->";
		}
	}
};
int main()
{
	return 0;
}
