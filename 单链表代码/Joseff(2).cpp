//Joseff
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
    LinkList( );  //建立没有头结点的空链表
    ~LinkList();  //析构函数
	void RInsert(T x);   //在链表表尾插入元素x
	void Create(int n);  //利用RInsert创建仅有尾指针的单向循环链表（不设置头结点）
	void Joseff(int m);
    void DispList( );     //遍历单链表，按序号依次输出各元素
 private:
   Node<T> *rear;  //尾指针
};

//创建空的循环表
template <class T>
LinkList<T>:: LinkList( ){
	rear=NULL;
}


//析构函数：释放链表结点所占内存单元
template <class T>  
LinkList<T>:: ~LinkList( ){   
    Node<T> *s;
	if(rear) //链表非空析构
	{
		s=rear->next;
		while (s!=rear){
			rear->next=s->next;
			delete s;
			s=rear->next;
		}
		delete s;
	}
}


//创建n个数据的链表
template <class T>  
void LinkList<T>::Create(int n){   
    int i;
	for(i=1;i<=n;i++)
		RInsert(i);
}
//Joseff
template <class T>  
void LinkList<T>::Joseff(int m){   
    int i;
	Node<T> *s;
	while(rear!=rear->next)
	{
		for(i=1;i<m;i++)
			rear=rear->next;
		s=rear->next;
		cout<<s->data<<" ";
		rear->next=s->next;
	}
	cout<<rear->data<<" "<<endl;	
}
/*
*前置条件：单链表存在
*输    入：插入元素x,
*功    能：将元素x插入到链表表尾位置
*输    出：无
*后置条件：单链表插入新元素
*/
template <class T>  
void LinkList<T>::RInsert(T x)
{  
   Node<T> *s;
   s=new Node<T>; 
   s->data=x;    //向内存申请一个结点s，其数据域为x
   if(rear)
   {
	   s->next=rear->next;  //将结点s插入到结点rear之后
	   rear->next=s;
	   rear=s;
   }
   else {
	   rear=s;
	   rear->next=rear;
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
	if(rear)  //链表非空输出数据
	{
		for(p=rear->next;p!=rear;p=p->next)
			cout<<p->data<<" ";
		cout<<p->data<<" ";
	}
	cout<<endl;
}
int main( ){
	LinkList<int> sa;
	int m,n;
	cin>>n>>m;
	sa.Create(n);  //创建n个人（编号1~n）的链表
   	sa.DispList(); // 遍历链表，输出编号
	sa.Joseff(m);  // 输出出圈人的编号次序
	return 0;
}