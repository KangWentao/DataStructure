//doubleDLinkList.cpp
#include <iostream>
#include <string>
using namespace std;

template <class T>
struct DNode
{
  T data;
  DNode<T> *prior, *next;  
};

template <class T>
class DLinkList
{
  public:
    DLinkList( );  //建立只有头结点的双向循环链表链表  
    ~DLinkList();        //析构函数
    int Length();        //求链表的长度
   	void Insert(T x);    //表尾插入x
	bool Judge( );       //判断对称
    void DispListF( );   //正向遍历链表，按照逻辑序号输出各元素
	void DispListR( );   //反向遍历链表，按照反向逻辑序号输出各元素
  
 private:
   DNode<T> *first;  //双向链表的头指针
};

/*
*前置条件：链表不存在
*输    入：无
*功    能：构建一个只有头结点的双向循环链表
*输    出：无
*后置条件：构建一个链表
*/
template <class T>
DLinkList<T>:: DLinkList( ){
	first=new DNode<T>; 
	first->next=first->prior=first;
}

/*
*前置条件：链表存在
*输    入：无
*功    能：释放链表各个结点所占内存单元
*输    出：无
*后置条件：链表结点被释放
*/
template <class T>
DLinkList<T>:: ~DLinkList()
{  
    DNode<T> *s;
	s=first->next;
	while (s!=first){
        first->next=s->next;
		delete s;
		s=first->next;
	}
	delete s;
}

/*
*前置条件：链表存在,
*输    入：插入元素x
*功    能：将元素x插入到链表表尾位置
*输    出：无
*后置条件：链表插入新元素
*/
template <class T>  
void DLinkList<T>::Insert(T x)
{  
   DNode<T> *s;
   s=new DNode<T>; 
   s->data=x;  //向内存申请一个结点s，其数据域为x
   s->next=first;       //将结点s插入到表尾
   s->prior=first->prior;
   first->prior=s;
   s->prior->next=s;
}

//判断单向链表对称，对称返回true，否则返回false
template <class T>
bool DLinkList<T>::Judge( ){
       DNode<T> *f, *r;
	   f=first->next;
	   r=first->prior;
       while (f!=r&& r->next!=f)
		   if (f->data!=r->data) 
			   return false;
		   else{
			   f=f->next;
			   r=r->prior;
		   }
	   return true;
}

/*
*前置条件：单链表存在
*输    入：无
*功    能：输出单链表长度
*输    出：单链表长度
*后置条件：单链表不变
*/
template <class T> 
int DLinkList<T>::Length( )
{
  DNode <T> *p = first->next;
  int count = 0;
  while(p!=first)
  { 
	  count++;
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
void DLinkList<T>::DispListF( )
{
	DNode<T> *p;
	cout<<"The length:"<<Length()<<endl;
	cout<<"The elements:\n";
	p=first->next;
	while (p!=first)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
	cout<<endl;
}/*
*前置条件：单链表存在
*输    入：无
*功    能：单链表遍历
*输    出：输出所有元素
*后置条件：单链表不变
*/
template <class T> 
void DLinkList<T>::DispListR( )
{
	DNode<T> *p;
	cout<<"The length:"<<Length()<<endl;
	cout<<"The elements:\n";
	p=first->prior;
	while (p!=first)
	{
	  cout<<p->data<<" ";
	  p=p->prior;
	}
	cout<<endl;
}
int main()
{
	DLinkList<string> DL;
	string subject;
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>subject;
		DL.Insert(subject);
	}
	DL.DispListF();
	DL.DispListR();
	return 0;
}

