#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *next;
	node()
	{
		next =  NULL;
	}
};

class l
{
 	public:
 	node *head;
 	node *tail;
 	l()
 	{
 		head = NULL;
 		tail = NULL;
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
		int n=0;
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
		while(i<=n)
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
		temp->data = value;	
		node *current =head;
		if(head == NULL)
		{
			head = temp;
		}
		else if(i==0)
		{
			node *temp = new node;
			temp->data = value;
			temp->next = head;
			head = temp;
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
		int i=0,j=0;
		if(i<0 && i>pos)
		{
			cout<<"Enter proper position";
		}
		else
		{
			if(pos==1)
			{
				current= current->next;
				delete temp;
				head= current;
			}
			else
			{
			while(i<pos-1)
			{
				current = current->next;
				i++;
			}
			while(j<pos)
			{
				temp = temp->next;
				j++;
			}
			current->next = temp->next;
			delete temp;
			}
		}
	}
	
	void tailchange()
	{
		node *tail = head;
		int i=0;
		int n = count();
		while(i<=n)
		{
			tail= tail->next;
		}
		
	}
 };
class stack
{
 	public:
 	node *top;
 	stack()
	{
		top = NULL;
	}
	
	l l1;
	void push(int value)
	{	
		l1.insert(value);
		top  = l1.head;			
	}	
	
	void pop()
	{
		l1.delat(1);
		top = l1.head;
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
	
	node* topdisplay()
	{
		top = l1.head;
		return top;
	}
	
	void display()
	{
		l1.disp();
	}
}; 
class queue
 {
 	public:
 	node *front;
 	queue()
	{
		front = NULL;
	}
	
	l l1;
	void enq(int value)
	{	
		front  = l1.head;	
		l1.insertat(value,0);		
	}	
	
	void dq()
	{
		l1.del();
		front = l1.head;
	}
	
	int size()
	{
		int n = l1.count();
		return n;
	}
	
	bool isEmpty()
	{
		if(front == NULL) return true;
		return false;
	}
	
	node* frontdisp()
	{
		front = l1.head;
		return front;
	}
	
	void display()
	{
		l1.disp();
	}
 };
 
 class qus
 {	
	public:
	stack s,temp;
	node *front;
	
	qus()
	{
		front =	NULL;
	}	
	
	void enque(int x)
	{
		s.push(x);
		front= s.topdisplay();
	}	
	void dq()
	{	
		while(s.top != NULL)
		{
			front = s.topdisplay();
	    	temp.push(front->data);
	    	s.pop();
		}
		temp.pop();
		while(temp.top != NULL)
		{	
			front=temp.topdisplay();
			s.push(front->data);
			temp.pop();
		}
	}
	void dqr()
	{
		int temp = s.top->data;
		s.pop();
		if(s.size()==0) return;
		else
		{
			dqr();
			s.push(temp);
		}
		
	}
	void disp()
		{
			s.display();
		}
	
};
 	class suq
	 {
	 	public:
	 	node* top;
	 	queue q,temp;
	 	suq()
	 	{
	 		top = NULL;
		}
	 	
	 	void push(int x)
	 	{
	 		q.enq(x);
	 		top= q.frontdisp()  ;
		}
		
		void pop()
		{
			while(top!= NULL)
			{
			top = q.frontdisp();
			temp.enq(top->data);
			q.front = NULL;
			}
			temp.dq();
			while(top != NULL)
			{
				top = temp.frontdisp();
				q.enq(top->data);
				temp.front = NULL; 
			}
		}
		
		void popr()
		{
			int temp = q.front->data;
			q.dq();
			if(q.size()==0) return;
			else
			{
			popr();
			q.enq(temp);	
			}
		}
		void display()
		{
			q.display();
		}
	 };
int main()
{	
	suq s;
	for(int i=0;i<5;i++)
	{
		s.push(i+1);
	}
	s.display();
	cout<<endl;
	s.pop();
	s.display();
	
	return 0;
}

