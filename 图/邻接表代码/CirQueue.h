//CirQueue.h
#ifndef CIRQUEUE_H
#define CIRQUEUE_H

const int QueueSize=100;  //定义存储队列元素的数组的最大长度

template <class T>        //定义模板类CirQueue
class CirQueue
{
public:
    CirQueue( );        //构造函数，置空队
    ~ CirQueue( );               //析构函数
    void EnQueue(T x);           //将元素x入队
    T DeQueue( );                //将队头元素出队
    T GetQueue( );               //取队头元素（并不删除）
    bool Empty( );               //判断队列是否为空
private:
    T data[QueueSize];           //存放队列元素的数组
    int front, rear;    //队头和队尾指针，分别指向队头元素的前一个位置和队尾元素的位置
};

#endif

template <class T>
CirQueue<T>::CirQueue( ) 
{
	front=rear=0;
} 

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：销毁队列
 * 输    出：无
 * 后置条件：释放队列所占用的存储空间
 */

template <class T>
CirQueue<T>::~CirQueue( )
{

}

/*
 * 前置条件：队列已存在
 * 输    入：元素值x
 * 功    能：在队尾插入一个元素
 * 输    出：如果插入不成功，抛出异常
 * 后置条件：如果插入成功，队尾增加了一个元素
 */

template <class T> 
void CirQueue<T>::EnQueue(T x)
{
    if ((rear+1) % QueueSize ==front) throw "上溢";
    rear=(rear+1) % QueueSize;   //队尾指针在循环意义下加1
    data[rear]=x;                //在队尾处插入元素
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：删除队头元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出删除异常
 * 后置条件：如果删除成功，队头减少了一个元素
 */

template <class T> 
T CirQueue<T>::DeQueue( )
{
    if (rear==front) throw "下溢"; 
    front=(front+1) % QueueSize;    //队头指针在循环意义下加1
    return data[front];             //读取并返回出队前的队头元素，注意队头指针
}
                                   //指向队头元素的前一个位置
/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：读取队头元素
 * 输    出：若队列不空，返回队头元素
 * 后置条件：队列不变
 */

template <class T>
T CirQueue<T>::GetQueue( )
{   
    int i;
    if (rear==front) throw "下溢"; 
    i=(front+1) % QueueSize;  //注意不要给队头指针赋值
    return data[i];
}

/*
 * 前置条件：队列已存在
 * 输    入：无
 * 功    能：判断队列是否为空
 * 输    出：如果队列为空，返回1，否则，返回0
 * 后置条件：队列不变
 */

template <class T> 
bool CirQueue<T>::Empty( ) 
{
    if (front==rear) 
		return 1; 
	else 
		return 0;
}