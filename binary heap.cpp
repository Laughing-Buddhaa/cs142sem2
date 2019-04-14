#include<iostream>
#include<climits>
using namespace std;

class heap
{
public:
	int *harr;		//pointer to array of elements in heap
	int csize;		//current size
	int msize;		//max size
	
	heap(int cap)
	{
		csize = 0;
		msize = cap;
		harr = new int[cap];
	}
	
	int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
	
	// Returns the minimum key (key at root) from min heap 
    int getMin() { return harr[0]; } 

    void insert(int i)
    {
    	if(csize==msize) 
		{
			cout<<"heap overflow";	
		}	
		
		harr[csize]= i;
		csize++;	
		
		int j= csize;
		j--;
		while(j!=0 && harr[parent(j)]>harr[j])
		{
			swap(&harr[parent(j)],&harr[j]);
			j=parent(j);	
		}	
	}
	
	void swap(int *a,int *b)
	{
		int *temp;
		*temp = *a;
		*a = *b;
		*b= *temp;
	}
	
	void display()
	{
		for(int i=0;i<csize;i++)
		{
			cout<<harr[i]<<",";
		}
	}
	
	int extractmin()
	{
		if(csize==0)
		{
			cout<<"heap is emmpty";
			return INT_MAX;
		}
		
		if(csize==1)
		{
			return harr[0];
			csize--;
			
		}
		int root = harr[0];
		harr[0] = harr[csize-1];
		csize--;
		minheapify(0);
		return root;
	}
	
	void decreasekey(int i,int val)
	{
		harr[i] = val;
		while(i!=0 && harr[i]<harr[parent(i)])
		{
			swap(&harr[parent(i)],&harr[i]);
			i=parent(i);
		}
	}
	void deletekey(int i)
	{
		decreasekey(i,INT_MIN);
		extractmin();
	}
	void minheapify(int i)
	{
		int l = left(i);
		int r= right(i);
		int s=i;
		if(l<csize && harr[l]<harr[i])	s=l;
		if(r<csize && harr[r]<harr[s])	s=r;
		if(s!=l)
		{
			swap(&harr[s],&harr[l]);
			minheapify(s);
		}
		
	}
};

int main(){
    heap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        
    }
    bh1.display();
    bh1.extractmin();
    
    bh1.display();
    bh1.deletekey(3);
    bh1.display();
    cout << endl;
}#include<iostream>
#include<climits>
using namespace std;

class heap
{
public:
	int *harr;		//pointer to array of elements in heap
	int csize;		//current size
	int msize;		//max size
	
	heap(int cap)
	{
		csize = 0;
		msize = cap;
		harr = new int[cap];
	}
	
	int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
	
	// Returns the minimum key (key at root) from min heap 
    int getMin() { return harr[0]; } 

    void insert(int i)
    {
    	if(csize==msize) 
		{
			cout<<"heap overflow";	
		}	
		
		harr[csize]= i;
		csize++;	
		
		int j= csize;
		j--;
		while(j!=0 && harr[parent(j)]>harr[j])
		{
			swap(&harr[parent(j)],&harr[j]);
			j=parent(j);	
		}	
	}
	
	void swap(int *a,int *b)
	{
		int *temp;
		*temp = *a;
		*a = *b;
		*b= *temp;
	}
	
	void display()
	{
		for(int i=0;i<csize;i++)
		{
			cout<<harr[i]<<",";
		}
	}
	
	int extractmin()
	{
		if(csize==0)
		{
			cout<<"heap is emmpty";
			return INT_MAX;
		}
		
		if(csize==1)
		{
			return harr[0];
			csize--;
			
		}
		int root = harr[0];
		harr[0] = harr[csize-1];
		csize--;
		minheapify(0);
		return root;
	}
	
	void decreasekey(int i,int val)
	{
		harr[i] = val;
		while(i!=0 && harr[i]<harr[parent(i)])
		{
			swap(&harr[parent(i)],&harr[i]);
			i=parent(i);
		}
	}
	void deletekey(int i)
	{
		decreasekey(i,INT_MIN);
		extractmin();
	}
	void minheapify(int i)
	{
		int l = left(i);
		int r= right(i);
		int s=i;
		if(l<csize && harr[l]<harr[i])	s=l;
		if(r<csize && harr[r]<harr[s])	s=r;
		if(s!=l)
		{
			swap(&harr[s],&harr[l]);
			minheapify(s);
		}
		
	}
};

int main(){
    heap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        
    }
    bh1.display();
    bh1.extractmin();
    
    bh1.display();
    bh1.deletekey(3);
    bh1.display();
    cout << endl;
}#include<iostream>
#include<climits>
using namespace std;

class heap
{
public:
	int *harr;		//pointer to array of elements in heap
	int csize;		//current size
	int msize;		//max size
	
	heap(int cap)
	{
		csize = 0;
		msize = cap;
		harr = new int[cap];
	}
	
	int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
	
	// Returns the minimum key (key at root) from min heap 
    int getMin() { return harr[0]; } 

    void insert(int i)
    {
    	if(csize==msize) 
		{
			cout<<"heap overflow";	
		}	
		
		harr[csize]= i;
		csize++;	
		
		int j= csize;
		j--;
		while(j!=0 && harr[parent(j)]>harr[j])
		{
			swap(&harr[parent(j)],&harr[j]);
			j=parent(j);	
		}	
	}
	
	void swap(int *a,int *b)
	{
		int *temp;
		*temp = *a;
		*a = *b;
		*b= *temp;
	}
	
	void display()
	{
		for(int i=0;i<csize;i++)
		{
			cout<<harr[i]<<",";
		}
	}
	
	int extractmin()
	{
		if(csize==0)
		{
			cout<<"heap is emmpty";
			return INT_MAX;
		}
		
		if(csize==1)
		{
			return harr[0];
			csize--;
			
		}
		int root = harr[0];
		harr[0] = harr[csize-1];
		csize--;
		minheapify(0);
		return root;
	}
	
	void decreasekey(int i,int val)
	{
		harr[i] = val;
		while(i!=0 && harr[i]<harr[parent(i)])
		{
			swap(&harr[parent(i)],&harr[i]);
			i=parent(i);
		}
	}
	void deletekey(int i)
	{
		decreasekey(i,INT_MIN);
		extractmin();
	}
	void minheapify(int i)
	{
		int l = left(i);
		int r= right(i);
		int s=i;
		if(l<csize && harr[l]<harr[i])	s=l;
		if(r<csize && harr[r]<harr[s])	s=r;
		if(s!=l)
		{
			swap(&harr[s],&harr[l]);
			minheapify(s);
		}
		
	}
};

int main(){
    heap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        
    }
    bh1.display();
    bh1.extractmin();
    
    bh1.display();
    bh1.deletekey(3);
    bh1.display();
    cout << endl;
}#include<iostream>
#include<climits>
using namespace std;

class heap
{
public:
	int *harr;		//pointer to array of elements in heap
	int csize;		//current size
	int msize;		//max size
	
	heap(int cap)
	{
		csize = 0;
		msize = cap;
		harr = new int[cap];
	}
	
	int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
	
	// Returns the minimum key (key at root) from min heap 
    int getMin() { return harr[0]; } 

    void insert(int i)
    {
    	if(csize==msize) 
		{
			cout<<"heap overflow";	
		}	
		
		harr[csize]= i;
		csize++;	
		
		int j= csize;
		j--;
		while(j!=0 && harr[parent(j)]>harr[j])
		{
			swap(&harr[parent(j)],&harr[j]);
			j=parent(j);	
		}	
	}
	
	void swap(int *a,int *b)
	{
		int *temp;
		*temp = *a;
		*a = *b;
		*b= *temp;
	}
	
	void display()
	{
		for(int i=0;i<csize;i++)
		{
			cout<<harr[i]<<",";
		}
	}
	
	int extractmin()
	{
		if(csize==0)
		{
			cout<<"heap is emmpty";
			return INT_MAX;
		}
		
		if(csize==1)
		{
			return harr[0];
			csize--;
			
		}
		int root = harr[0];
		harr[0] = harr[csize-1];
		csize--;
		minheapify(0);
		return root;
	}
	
	void decreasekey(int i,int val)
	{
		harr[i] = val;
		while(i!=0 && harr[i]<harr[parent(i)])
		{
			swap(&harr[parent(i)],&harr[i]);
			i=parent(i);
		}
	}
	void deletekey(int i)
	{
		decreasekey(i,INT_MIN);
		extractmin();
	}
	void minheapify(int i)
	{
		int l = left(i);
		int r= right(i);
		int s=i;
		if(l<csize && harr[l]<harr[i])	s=l;
		if(r<csize && harr[r]<harr[s])	s=r;
		if(s!=l)
		{
			swap(&harr[s],&harr[l]);
			minheapify(s);
		}
		
	}
};

int main(){
    heap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        
    }
    bh1.display();
    bh1.extractmin();
    
    bh1.display();
    bh1.deletekey(3);
    bh1.display();
    cout << endl;
}
