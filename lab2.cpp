#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	
	node()
	{
		next = NULL;
	}
};
class l
{
	node *head;
	node *tail;
	
	l()
	{
		head = NULL;
		tail = NULL;
	}
	
	void insert(int value)
	{
		node *temp = new node;
		temp->data = value;
		if(head = NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
		}	
		tail = temp;
	}
	int count()
	{
		int n=0;
		node *current ;
		current  = head;
		while(current->next != NULl)
		{
			n++;
			current = current->next;
		}
		return n;
	}
	 
	void insertat(int value, int pos)
	{
		int n= count();
		int i=1;
		if*(pos>n)
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
	 	node *temp = tail;
	 	while(current->next != tail)
		 	{
	 			current= current->next;
			}
		current->next = NULL;
		tail = current;
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
		while(current->next != NULL)
		{
			cout<<current->data<<"->";
		}
	}
	
	void revdis()
	{
		redisp(head);
		cout<<endl;
	}
	
	void revdisp(node *current)
	{
		if(current == NULL)
		return;
		else 
		{
			revdisp(current->next);
			cout<<current->data<<"->";
		}
	}
	void revlist()
	{
		node *temp;
		revl(head);
		temp->next = NULL;
	}	 
	void revl(node *current)
	{
		if(current =NULL) return;
		else if(current->next = NULL)
		{
			head = current;
			return;
		}
		else
		{
			revl(current->next);
			current->next->next = current;
		}
	}
};
int main()
{
	return 0;
}
