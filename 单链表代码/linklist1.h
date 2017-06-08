//LinkList.h  声明类LinkList
#ifndef LinkList_H
#define LinkList_H
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
   
	friend void Divide(LinkList<T> &A, LinkList<T> &B,LinkList<T> &C);



    friend void Merge(LinkList<T> &La, LinkList<T> Lb);
 private:
   Node<T> *first;  //单链表的头指针
};

//LinkList.cpp

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


template <class T>
void Divide(LinkList<T> &A, LinkList<T> &B, LinkList<T>&C)
{
	Node <T> *p,*s;
	p=A.first; 
	s=p->next; 
	while(s)
		if (s->data>='a'&&s->data<='z')
		{p=p->next;
		s=s->next;
		}
		else if(s->data>='0'&&s->data<='9')
		{
			p->next=s->next;
			s->next=B.first->next;
			B.first->next=s;
			s=p->next;
		}
		else {
			p->next=s->next;
			s->next=C.first->next;
			C.first->next=s;
			s=p->next;
		}
}   


//merge sorted list
  
template <class T>
void Merge(LinkList<T> &La, LinkList<T> &Lb){
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
	  cout<<p->data<<"  ";
	  p=p->next;
	}
	cout<<endl;
}

#endif
