//circular linklist
#include <iostream>
using namespace std;
//结点结构
template <class T>
struct Node
{
  T data;
  Node<T> *next;  
};
//单向循环链表类
template <class T>
class LinkList
{
  public:
    LinkList( );  //建立只有头结点的空链表
    ~LinkList();  //析构函数
    int Length();    //求单链表的长度
    void Insert(T x);   //在单链表中的表尾位置插入元素值为x的结点
	void Reverse( );      //逆置链表
    void DispList( );     //遍历单链表，按序号依次输出各元素
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
	first->next=first;
}


/*
*前置条件：链表存在
*输    入：无
*功    能：释放链表各个结点所占内存单元
*输    出：无
*后置条件：链表结点被释放
*/
template <class T>  
LinkList<T>:: ~LinkList( ){   
    Node<T> *s;
	s=first->next;
	while (s!=first){
        first->next=s->next;
		delete s;
		s=first->next;
	}
	delete s;
}


/*
*前置条件：单链表存在
*输    入：插入元素x,
*功    能：将元素x插入到链表表尾位置
*输    出：无
*后置条件：单链表插入新元素
*/
template <class T>  
void LinkList<T>::Insert(T x)
{  
   Node<T> *rear;    
   //Locate position 
    
   for(rear=first;rear->next!=first;rear=rear->next);
   Node<T> *s;
   s=new Node<T>; 
   s->data=x;    //向内存申请一个结点s，其数据域为x
   s->next=rear->next;  //将结点s插入到结点rear之后
   rear->next=s;
}


//单向链表逆置
template <class T>
void LinkList<T>::Reverse( ){
       Node<T> *p, *s;
	   p=first->next; 
       first->next=first;
       while (p!=first){
            s=p;
			p=p->next;
            s->next=first->next;
            first->next=s;
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
  Node <T> *p;
  int count=0;
  for(p=first->next;p!=first;p=p->next)
	  count++;
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
	for(p=first->next;p!=first;p=p->next)
		cout<<p->data<<" ";
	cout<<endl;
}
int main( ){
	LinkList<int> sa;
	int x;
	while(1)
	{
		cin>>x;
        if(!x)break;
		sa.Insert(x);		
	}
   	sa.DispList();
	sa.Reverse();
	sa.DispList();
	return 0;
}