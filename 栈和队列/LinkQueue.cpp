//LinkQueue.cpp
#include <iostream>
using namespace std;
template <class T>
struct Node
{
      T data;
      Node<T> *next;  //此处<T>也可以省略
};

template <class T>
class LinkQueue
{
public:
    LinkQueue( );      //构造函数，初始化一个仅有头结点的空队列
    ~LinkQueue( );      //析构函数，释放链队列中各结点的存储空间
    void EnQueue(T x);  //将元素x入队
    T DeQueue( );       //将队头元素出队，若队列为空，抛出异常“Downflow”，否则函数返回值为队头元素值
    T GetQueue( );     //取链队列的队头元素，若队列为空，抛出异常“Downflow”，否则函数返回值为队头元素值
    bool Empty( );     //判断链队列是否为空，为空返回true，否则返回false
private:
    Node<T> *front, *rear;  //队头和队尾指针，分别指向头结点和终端结点
};

/*
 * 前置条件：队列不存在
 * 输    入：无
 * 功    能：初始化队列
 * 输    出：无
 * 后置条件：创建一个空队列
 */

template <class T>
LinkQueue<T>::LinkQueue( )
{
	front=rear=new Node<T>;	
}

/*
 * 前置条件：队列存在
 * 输    入：无
 * 功    能：销毁队列
 * 输    出：无
 * 后置条件：释放队列所占用的存储空间
 */

template <class T>
LinkQueue<T>::~LinkQueue( )
{
	while(front)
	{
		Node <T> *p;
		p=front->next;
        delete front;
	    front=p;
	}
}

/*
 * 前置条件：队列已存在
 * 输    入：元素值s
 * 功    能：在队尾插入一个元素
 * 输    出：无
 * 后置条件：如果插入成功，队尾增加了一个元素
 */

template <class T> 
void LinkQueue<T>::EnQueue(T x)
{
	Node<T> *s;
    s=new Node<T>; 
    s->data=x;          //申请一个数据域为x的结点s
    s->next=NULL;
    rear->next=s;       //将结点s插入到队尾
    rear=s;
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：删除队头元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出删除异常
 * 后置条件：如果删除成功，队头减少了一个元素
 */

template <class T>
T LinkQueue<T>::DeQueue()
{    
	Node <T> *s; 
	T x;
    if (rear==front) throw "Downflow";
    s=front->next; 
	x=s->data;                       //暂存队头元素
    front->next=s->next;             //将队头元素所在结点摘链
    if (s->next==NULL) rear=front;   //判断出队前队列长度是否为1
    delete s;
    return x;
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：读取队头元素
 * 输    出：若队列不空，返回队头元素
 * 后置条件：队列不变
 */

template <class T> 
T LinkQueue<T>::GetQueue()
{
    if (front==rear) 
		throw"Downflow";
	else
		return front->next->data;
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：判断队列是否为空
 * 输    出：如果队列为空，返回1，否则，返回0
 * 后置条件：队列不变
 */

template <class T> 
bool LinkQueue<T>::Empty( )
{
    return front==rear;
}

int main()
{
	LinkQueue <int> Q1;
	int x;
	while(1)
	{
		cin>>x;
		if(!x) break;
		Q1.EnQueue(x);
	}
	cout<<"DeQueue:";
	while(!Q1.Empty())
	{
		x=Q1.DeQueue();
		cout<<x<<" ";
	}
	try{
		x=Q1.DeQueue();
		cout<<x<<" ";
	}
	catch(const char *ms)
	{
		cout<<ms<<endl;
	}
	cout<<"GetQueue:";
	try{
		x=Q1.GetQueue();
		cout<<x<<" ";
	}
	catch(const char *ms)
	{
		cout<<ms<<endl;
	}
	return 0;
}