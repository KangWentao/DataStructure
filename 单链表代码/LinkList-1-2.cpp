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
    ~LinkList();             //析构函数
    int Length();          //求单链表的长度
    int Locate(T x);       //求单链表中值为x的元素序号
    void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
	void Reverse( );        //reverse list
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
	int count=0;
	for(p=first->next;p;p=p->next)
	{
		count++;
		if (p->data==x) break;
	}
	if(p) return count;	
	else return 0;
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
   Node<T> *p; 
   int count;    
   //Locate position i-1
   count=0;   
   for(p=first;p->next;p=p->next)
   {
	   if (count>=i-1)break;
	   count++;
   }
   if (i<1||count<i-1) throw "Illegal inserted position";
   else { 
	  Node<T> *s;
      s=new Node<T>; 
	  s->data=x;    //向内存申请一个结点s，其数据域为x
      s->next=p->next;  //将结点s插入到结点p之后
      p->next=s;
	}
}


//单向链表逆置
template <class T>
void LinkList<T>::Reverse( ){
       Node<T> *p, *s;
	   p=first->next; 
       first->next=NULL;
       while (p){
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
  for(p=first->next;p;p=p->next)
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
	for(p=first->next;p;p=p->next)
		cout<<p->data<<" ";
	cout<<endl;
}
int main( ){
	LinkList<int> sa;
	int x;
	int i=1;
	while(1)
	{
		cin>>x;
        if(!x)break;
		try{
			sa.Insert(i++,x);
		}
		catch(char *ms)
		{
			cout<<ms<<endl;
		}
	}
    
	cin>>x;
	sa.DispList();
	int pos=sa.Locate(x);
	if(!pos) cout<<"No found\n";
	else
		cout<<"Found position:"<<pos<<endl;	
	sa.Reverse();
	sa.DispList();
	return 0;
}