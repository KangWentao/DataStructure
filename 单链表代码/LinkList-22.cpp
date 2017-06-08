//LinkSortList
#include <iostream>
using namespace std;
template <class T>
struct Node
{
  T data;
  Node<T> *next;  //此处<T>也可以省略
};
//有序单链表类
template <class T>
class LinkSortList
{
  public:
    LinkSortList( );  //建立只有头结点的空链表
    ~LinkSortList();             //析构函数
    void Insert(T x);   //在有序单链表中插入元素x使序列仍有序
    int Length();      //求表长
    int DeleteOdd();     //在单链表中删除所有奇数，返回值为奇数个数
    void DispList( );     //遍历有序单链表，按序号依次输出各元素
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
LinkSortList<T>:: LinkSortList( ){
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
LinkSortList<T>:: ~LinkSortList( ){   
    Node<T> *s;
	while (first){
        s=first;
		first=first->next;
        delete s;
    }
}


/*
*前置条件：单链表存在
*输    入：插入元素x,使序列仍有序
*功    能：将元素x插入到单链表的有序位置
*输    出：无
*后置条件：单链表插入新元素
*/
template <class T>  
void LinkSortList<T>::Insert(T x)
{  
   Node<T> *p; 
   p=first; //工作指针p初始化
   while (p->next && p->next->data<x)
	   p=p->next;   //工作指针p后移
   
   Node<T> *s;
   s=new Node<T>; 
   s->data=x;  //向内存申请一个结点s，其数据域为x
   s->next=p->next;       //将结点s插入到结点p之后
   p->next=s;
	
}


/*
*前置条件：单链表存在
*输    入：无
*功    能：删除单链表中所有奇数结点
*输    出：无
*后置条件：单链表删除元素
*/
template <class T>  
int LinkSortList<T>::DeleteOdd()
{ 
  Node<T> *p,*s; 
  int count=0;
  p=first ;  //工作指针p初始化
  while (p->next) 
    if(p->next->data%2)
	{
		s=p->next;
		p->next=s->next;
		delete s;
		count++;
	}
	else 
		p=p->next;
	return count;
}
template <class T> 
int LinkSortList<T>::Length( )
{
	Node<T> *p;
	int count=0;
	p=first->next;
	while (p)
	{
	  count++;
	  p=p->next;
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
void LinkSortList<T>::DispList( )
{
	Node<T> *p;
	cout<<"The length:"<<Length()<<endl;
	cout<<"The elements:";
	p=first->next;
	while (p)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
	cout<<endl;
}
int main( ){
	LinkSortList<int> sa;
	int x;
	while(1)
	{
		cin>>x;
        if(!x)break;
		sa.Insert(x);		
	}
    sa.DispList();
	int count=sa.DeleteOdd();
	cout<<"Count of deleted odds:"<<count<<endl;
	sa.DispList();
	return 0;
} 