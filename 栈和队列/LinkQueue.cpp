//LinkQueue.cpp
#include <iostream>
using namespace std;
template <class T>
struct Node
{
      T data;
      Node<T> *next;  //�˴�<T>Ҳ����ʡ��
};

template <class T>
class LinkQueue
{
public:
    LinkQueue( );      //���캯������ʼ��һ������ͷ���Ŀն���
    ~LinkQueue( );      //�����������ͷ��������и����Ĵ洢�ռ�
    void EnQueue(T x);  //��Ԫ��x���
    T DeQueue( );       //����ͷԪ�س��ӣ�������Ϊ�գ��׳��쳣��Downflow��������������ֵΪ��ͷԪ��ֵ
    T GetQueue( );     //ȡ�����еĶ�ͷԪ�أ�������Ϊ�գ��׳��쳣��Downflow��������������ֵΪ��ͷԪ��ֵ
    bool Empty( );     //�ж��������Ƿ�Ϊ�գ�Ϊ�շ���true�����򷵻�false
private:
    Node<T> *front, *rear;  //��ͷ�Ͷ�βָ�룬�ֱ�ָ��ͷ�����ն˽��
};

/*
 * ǰ�����������в�����
 * ��    �룺��
 * ��    �ܣ���ʼ������
 * ��    ������
 * ��������������һ���ն���
 */

template <class T>
LinkQueue<T>::LinkQueue( )
{
	front=rear=new Node<T>;	
}

/*
 * ǰ�����������д���
 * ��    �룺��
 * ��    �ܣ����ٶ���
 * ��    ������
 * �����������ͷŶ�����ռ�õĴ洢�ռ�
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
 * ǰ�������������Ѵ���
 * ��    �룺Ԫ��ֵs
 * ��    �ܣ��ڶ�β����һ��Ԫ��
 * ��    ������
 * �����������������ɹ�����β������һ��Ԫ��
 */

template <class T> 
void LinkQueue<T>::EnQueue(T x)
{
	Node<T> *s;
    s=new Node<T>; 
    s->data=x;          //����һ��������Ϊx�Ľ��s
    s->next=NULL;
    rear->next=s;       //�����s���뵽��β
    rear=s;
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ�ɾ����ͷԪ��
 * ��    �������ɾ���ɹ������ر�ɾԪ��ֵ�������׳�ɾ���쳣
 * �������������ɾ���ɹ�����ͷ������һ��Ԫ��
 */

template <class T>
T LinkQueue<T>::DeQueue()
{    
	Node <T> *s; 
	T x;
    if (rear==front) throw "Downflow";
    s=front->next; 
	x=s->data;                       //�ݴ��ͷԪ��
    front->next=s->next;             //����ͷԪ�����ڽ��ժ��
    if (s->next==NULL) rear=front;   //�жϳ���ǰ���г����Ƿ�Ϊ1
    delete s;
    return x;
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ���ȡ��ͷԪ��
 * ��    ���������в��գ����ض�ͷԪ��
 * �������������в���
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
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ��ж϶����Ƿ�Ϊ��
 * ��    �����������Ϊ�գ�����1�����򣬷���0
 * �������������в���
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