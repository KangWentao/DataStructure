//LinkList-4 divide into A and B
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
    ~LinkList();             //析构函数
    int Length();          //求单链表的长度
    void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
    void Divide(LinkList<T> &A,LinkList<T> &B); //将当前链表分解为A，B表
    void DispList( );           //遍历单链表，按序号依次输出各元素
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
LinkList<T>:: ~LinkList( ){   
    Node<T> *s;
	while (first){
        s=first;
		first=first->next;
        delete s;
    }
}

//将当前链表分解为A，B表
template<class T>
void LinkList<T>::Divide(LinkList<T> &A,LinkList<T> &B)
{
	Node<T>*p,*s;
	p=first->next;
	first->next=NULL;
	while(p)
	{
		if (p->data%2) {
			s=p;
			p=p->next;
			s->next=A.first->next;
			A.first->next=s;
		}
		else{	
			s=p;
			p=p->next;
			s->next=B.first->next;
			B.first->next=s;
		}
	}
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
  int count = 0;
  while(p)
  { count++;
    p = p->next;   
  }
  return count;
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
	cout<<"The length:"<<Length()<<endl;
	cout<<"The elements:\n";
	p=first->next;
	while (p)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
	cout<<endl;
}
int main( ){
	LinkList<int> A,B,C;
	int x,i=1;
	while(1)
	{
		cin>>x;
        if(!x)break;
		try{
			C.Insert(i++,x);
		}
		catch(char *ms)
		{
			cout<<ms<<endl;
		}
	}    
	C.DispList();
	C.Divide(A,B);
	C.DispList();
	A.DispList();
	B.DispList();
	return 0;
}
/*
23 2 42 4 1121 27 40 0
The length:7
The elements:
23 2 42 4 1121 27 40 
The length:0
The elements:

The length:3
The elements:
27 1121 23 
The length:4
The elements:
40 4 42 2 
*/
