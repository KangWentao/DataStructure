#include<iostream>        
using namespace std;
const int MaxSize=11;    //maxsize
struct Node
{
	int data;
    Node *next;  
};

class LinkHash
{
public:
	LinkHash();  //initialize an empty list
	int HashFunc(int k);  //hash function
	int HashSearch(int k); //dynamic search k
	void Display();
    double HashASL();
private:
   Node *ht[MaxSize];  //ht数组用来保留各个链表的头指针
};

//hash function
int LinkHash::HashFunc(int k)
{
	return k%11;   //hash函数，假设为除余法，余数为11
}

//constructor:initialize an empty hashlist
LinkHash::LinkHash()
{
	int i;
	for(i=0;i<MaxSize;i++)
		ht[i]=NULL;  //NULL is empty
}
void LinkHash::Display()
{
	int i;
	for(i=0;i<MaxSize;i++)
	{
		cout<<"Hash address:"<<i<<",value:";
		Node *p;
		for(p=ht[i];p;p=p->next)
			cout<<p->data<<" ";
		cout<<endl;
	}
}
int LinkHash::HashSearch(int k)
{       
    Node *p; 
	int n=0,hashadd=HashFunc(k);
	for(p=ht[hashadd];p;p=p->next)
	{
		n++;
		if(p->data==k) return n;
	}	
	Node *s;
    s=new Node; 
	s->data=k;             
    s->next=ht[hashadd];      
    ht[hashadd]=s;
	return n+1;  //
}

double LinkHash::HashASL()
{
	int i,n=0,c;
	double ASL=0;
	for(i=0;i<MaxSize;i++)
	{
		Node *p;
		c=0;		
		for(p=ht[i];p;p=p->next)
		{
			c++;
			ASL+=c;
			n++;
		}
	}
	return ASL/n;
}
int main()
{
	LinkHash LS;
 	int k;
	while(1)
	{		
		cin>>k;
		if(!k) break;
		LS.HashSearch(k); 
	}
	LS.Display(); 	
//	cout<<LS.HashSearch(7)<<LS.HashSearch(18);  
	cout<<"ASL="<<LS.HashASL();
	return 0;
}
/*
47 7 29 11 16 92 22 8 3 29 0
Hash address:0,value:22 11
Hash address:1,value:
Hash address:2,value:
Hash address:3,value:3 47
Hash address:4,value:92
Hash address:5,value:16
Hash address:6,value:
Hash address:7,value:29 7
Hash address:8,value:8
Hash address:9,value:
Hash address:10,value:
ASL=1.33333

47 7 29 11 16 92 22 8 3 22 19 30 0
Hash address:0,value:22 11
Hash address:1,value:
Hash address:2,value:
Hash address:3,value:3 47
Hash address:4,value:92
Hash address:5,value:16
Hash address:6,value:
Hash address:7,value:29 7
Hash address:8,value:30 19 8
Hash address:9,value:
Hash address:10,value:
ASL=1.54545
*/