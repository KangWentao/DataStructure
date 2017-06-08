//LinkQueue.cpp
#include "LinkQueue.h"

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
	Node <T> *s;
	s=new Node<T>;
	s->next=NULL;
	front=rear=s;
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
	Node <T> *p; int x;
    if (rear==front) throw "下溢";
    p=front->next; 
	x=p->data;                       //暂存队头元素
    front->next=p->next;             //将队头元素所在结点摘链
    if (p->next==NULL) rear=front;   //判断出队前队列长度是否为1
    delete p;
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
    if (front!=rear) 
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
    if(front==rear) 
		return 1;
    else 
		return 0;
}