//LinkSortList-1 basic operations
#include <iostream>
using namespace std;
template <class T>
struct Node
{
  T data;
  Node<T> *next;  //此处<T>也可以省略
};

template <class T>
class LinkSortList
{
  public:
    LinkSortList( );  //建立只有头结点的空链表
    ~LinkSortList();             //析构函数
 	void Insert(T x);        //sort insert
	int Length();
    void DispList( );           //遍历单链表，按序号依次输出各元素
    void Merge(LinkSortList<T> &A, LinkSortList<T> &B);  //合并A,B到当前类 
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
*前置条件：无
*输    入：无
*功    能：无
*输    出：无
*后置条件：无
*/
template <class T>
LinkSortList<T>:: ~LinkSortList()
{  
	Node<T> *s;
	while (first){
        s=first;
		first=first->next;
        delete s;
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
void LinkSortList<T>::Insert(T x)
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


//merge sorted list
  
template <class T>
void LinkSortList<T>::Merge(LinkSortList<T> &A, LinkSortList<T> &B){
	Node <T> *pa, *pb, *rear;
	pa=A.first->next;
	A.first->next=NULL;  
	pb=B.first->next;
	B.first->next=NULL;
	rear=first;
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
	LinkSortList <int> A,B,C;
	int x;
	while(1){
		cin>>x;
		if(!x) break;
		A.Insert(x);
	}
	while(1){
		cin>>x;
		if(!x) break;
		B.Insert(x);
	}
	A.DispList();
	B.DispList();
	C.Merge(A,B);
	C.DispList();
    A.DispList();
	B.DispList();
	return 0;	
}