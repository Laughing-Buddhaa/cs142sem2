//comments don't matter so much
#include<iostream>
using namespace std;
class node			//create a class node
{
	public:
	int data;		//data
	node *link;		//pointer to the next node
	node()			//default constructor
	{
		link = NULL;
	}
};

class ll{			//linked list
	public:
	node *head;
	node *tail;
	
	ll()			//default constructor
	{
		head = NULL;
		tail = NULL;
	}
	void insert(int value)		//insert function
	{
		node *temp = new node;
		temp->data = value;
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}	
		else
		{
			tail->link = temp;
		}
		tail = temp;
	}
	void del()					//delete function
	{
		//store the tail in temp
		node *temp = tail;
		//before the tail has to point to null
		node *current = head;
		while(current->link != tail)
		{
			current = current->link;
		}
		current->link = NULL;
		tail = current;
		//delete temp;
		delete temp;
	}
	
	int count()					//count function
	{
		int n=0;
		node *current = head;
		while(current != NULL)
		{
			n++;
			current=current->link;	
		}
		return n;
	}
	void insertat(int pos, int value)q	//insertat function
	{
		node *current = head;
		int i=1; 
		while(i<pos-1)
		{
			i++;
			current = current->link;
		}
		int n= count();
		if(pos>n)
		{
			cout<<"position doesn't exist";
		}
		//create a node
		node *temp= new node;
		temp->data = value;
		temp->link = current->link ;
		current->link= temp;
	}
	
	
	void delat(int pos)				//deleteat function
	{
		int n= count();
		if(pos>n)
		{
			cout<<"position doesn't exist";
		}
		else
		{
		node *alpha= head;
		int i=1; 
		while(i<pos-1)
		{
			i++;
			alpha = alpha->link;
		}
		node *beta= head;
		int j=1; 
		while(j<pos)
		{
			j++;
			beta = beta->link;
		}
		//del a node
		alpha->link = beta->link;
		delete beta;
	}
	}
	
	void display()					//display function
	{
		node *current = head;
		while(current != NULL)
		{
			cout<<current->data<<"->";
			current= current->link;
		}
	}

};
int main()
{
	ll list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.display();
	int n = list.count();
	cout<<n;
	list.del();
	list.display();
	list.delat(2);
	list.display();

	return 0;

