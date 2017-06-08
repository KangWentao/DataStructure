//LinkList-1 basic operations
#include <iostream>
using namespace std;
template <class T>
struct Node
{
  T data;
  Node<T> *next;  //此处<T>也可以省略
};

template <class T>
class LinkList
{
  public:
    LinkList( );  //建立只有头结点的空链表
    LinkList(T a[ ], int n);  //建立有n个元素的单链表
    ~LinkList();             //析构函数
    int Length();          //求单链表的长度
    T Get(int i);           //取单链表中第i个结点的元素值
    int Locate(T x);       //求单链表中值为x的元素序号
    void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
	void Insert(T x);        //sort insert
	void Exchange( );        //exchange list
    T Delete(int i);        //在单链表中删除第i个结点
    void DispList( );           //遍历单链表，按序号依次输出各元素
    friend void Divide(LinkList<T> &La, LinkList<T> &Lb);
    friend void Merge(LinkList<T> &La, LinkList<T> Lb);
 private:
   Node<T> *first;  //单链表的头指针
};
/*
*前置条件：单链表不存在
*输    入：无
*功    能：构建一个单链表
*输    出：无
*后置条件：构建一个单链表
*/
template <class T>
LinkList<T>:: LinkList( ){
	first=new Node<T>; 
	first->next=NULL;
}


/*
*前置条件：无
*输    入：无
*功    能：无
*输    出：无
*后置条件：无
*/
template <class T>
LinkList<T>:: ~LinkList()
{
}

/*
*前置条件：单链表存在
*输    入：查询元素位置i
*功    能：按位查找位置为i的元素并输出值
*输    出：查询元素的值
*后置条件：单链表不变
*/
template <class T>
T LinkList<T>::Get(int i){   
	Node<T> *p;
	int j;
    p=first;  
	j=0;  
	while (p && j<i){
		p=p->next;       //工作指针p后移
        j++;
	}
    if (!p) throw "位置非法";
    else return p->data;
}

/*
*前置条件：单链表存在
*输    入：查询元素值x
*功    能：按值查找值的元素并输出位置
*输    出：查询元素的位置
*后置条件：单链表不变
*/
template <class T> 
int LinkList<T>::Locate(T x){
	Node<T> *p; 
	int j;
	p=first->next;
	j=0;
	while(p){
		j++;
		if (p->data==x)return j;
		p=p->next;
	    
	}
	throw "表中无该元素";	
}

/*
*前置条件：单链表存在
*输    入：插入元素x,插入位置i
*功    能：将元素x插入到单链表中位置i处
*输    出：无
*后置条件：单链表插入新元素
*/
template <class T>  
void LinkList<T>::Insert(int i, T x)
{  
   Node<T> *p; int j;
   p=first; j=0;    //工作指针p初始化
   while (p && j<i-1)
   {
     p=p->next;   //工作指针p后移
     j++;
   }
   if (!p) throw "插入位置非法";
    else { 
	  Node<T> *s;
      s=new Node<T>; 
	  s->data=x;  //向内存申请一个结点s，其数据域为x
      s->next=p->next;       //将结点s插入到结点p之后
      p->next=s;
	}
}

/*
*前置条件：单链表存在,且元素非递减有序
*输    入：插入元素x
*功    能：将元素x插入到单链表的有序位置
*输    出：无
*后置条件：单链表插入新元素，且有序
*/
template <class T>  
void LinkList<T>::Insert(T x)
{  
   Node<T> *p; 
   p=first;     //工作指针p初始化
   while (p->next && p->next->data<=x)
        p=p->next;   //工作指针p后移
   Node<T> *s;
   s=new Node<T>; 
   s->data=x;  //向内存申请一个结点s，其数据域为x
   s->next=p->next;       //将结点s插入到结点p之后
   p->next=s;
}

//单向链表逆置
template <class T>
void LinkList<T>::Exchange( ){
       Node<T> *p, *q;
	   p=first->next; 
       first->next=NULL;
       while (p){
            q=p->next;
            p->next=first->next;
            first->next=p;
            p=q;
       }
}

//divide
template <class T>
void Divide(LinkList<T> &La, LinkList<T> &Lb){
	Node <T> *p,*q;
	p=La.first;
	while(p->next)
		if (p->next->data%2==1)
			p=p->next;
		else {
			q=p->next;
			p->next=q->next; 
			q->next=Lb.first->next; //Lb.Insert(1,q->data);
			Lb.first->next=q;            // delete q;
		}
}   

//merge sorted list
  
template <class T>
void Merge(LinkList<T> &La, LinkList<T> Lb){
	Node <T> *pa, *pb, *rear;
	pa=La.first->next;
	La.first->next=NULL;  
	pb=Lb.first->next; 
	rear=La.first;
	while(pa&&pb){
		if (pa->data<=pb->data)
		{ 
			rear->next=pa;
			pa=pa->next;
		}
		else
		{
			rear->next=pb;
			pb=pb->next;
		}
	    rear=rear->next;
	}
    if (pa) 
		rear->next=pa;
	else 
		rear->next=pb;
}     


/*
*前置条件：单链表存在
*输    入：无
*功    能：输出单链表长度
*输    出：单链表长度
*后置条件：单链表不变
*/
template <class T> 
int LinkList<T>::Length( )
{
  Node <T> *p = first->next;
  int i = 0;
  while(p)
  { i++;
    p = p->next;
   
  }
  return i;
}
/*
*前置条件：单链表存在
*输    入：要删除元素位置i
*功    能：删除单链表中位置为i的元素
*输    出：无
*后置条件：单链表删除元素
*/
template <class T>  
T LinkList<T>::Delete(int i)
{ 
  Node<T> *p; int j;
  p=first ; j=0;  //工作指针p初始化
  while (p && j<i-1)  //查找第i-1个结点
  {
    p=p->next;
    j++;
  }
  if (!p || !p->next) throw "位置";  //结点p不存在或结点p的后继结点不存在
    else {
		  Node<T> *q; int x;
          q=p->next; x=q->data;  //暂存被删结点
          p->next=q->next;  //摘链
          delete q; 
          return x;
	}
}
/*
*前置条件：单链表存在
*输    入：无
*功    能：单链表遍历
*输    出：输出所有元素
*后置条件：单链表不变
*/
template <class T> 
void LinkList<T>::DispList( )
{
	Node<T> *p;
	cout<<"The elements: ";
	p=first->next;
	while (p)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
	cout<<endl;
}
void main( ){
	int i,choi;
	int x;
        LinkList <int> A; //normal list1   
	
	do{
		cout<<"\n 0 exit       1 Insert       2 Delete \n";
		cout<<" 3 Get(i)     4  Locate(x)   5 Exchange\n";
		cout<<" 6 Divide     7  DispList"<<endl;
		cout<<" 8 Create a sorted list, then display\n";
		cout<<" please choice..."<<endl;
		cin>>choi;		
		try{
			switch(choi){
			case 0:
				break;
			case 1:	
                cout<<"Input the position and an element\n";
				cin>>i>>x;
				A.Insert(i,x);			
				break;
			case 2:
				cout<<"Input the position of the deleted element\n";
				cin>>i;
				A.Delete(i);
				break;
			case 3:
                cout<<"Input the position of the searched element\n";
				cin>>i;
				x=A.Get(i);
				cout<<"Element of i:"<<x<<endl;
				break;
			case 4:
                cout<<"Input the located element\n";
				cin>>x;
				i=A.Locate(x);
				cout<<"Position of x: "<<i<<endl;
				break;
			case 5:
				A.Exchange();
				break;
			case 6:
				{
					LinkList <int> B;
					Divide(A,B);
					A.DispList();
					B.DispList();
				}
				break;
			case 7:
				A.DispList();
				break;
			case 8:
				{
					LinkList<int> B, C;
					cout<<"Input 5 data(int): ";
					for (i=1;i<=5;i++){
						cin>>x;
						B.Insert(x);
					}
					B.DispList();
					cout<<"Input 5 data(int): ";
					for (i=1;i<=5;i++){
						cin>>x;
						C.Insert(x);
					}
					C.DispList();
					Merge(B,C);
					B.DispList();
				}
				break;
				
			default:
				throw "Choice error";
			}
		}
		catch(char *wrong){
			cout<<wrong<<endl;
		}
	}while(choi);
}