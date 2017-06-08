//CirQueue.cpp
#include <iostream>
#include <string>
using namespace std;
const int QueueSize=5;
template <class T>        //����ģ����CirQueue
class CirQueue
{
public:
    CirQueue( );                 //���캯�����ÿն�
    ~ CirQueue( );               //��������
    void EnQueue(T x);           //��Ԫ��x���
    T DeQueue( );                //����ͷԪ�س���
    T GetQueue( );               //ȡ��ͷԪ�أ�����ɾ����
    bool Empty( );               //�ж϶����Ƿ�Ϊ�գ��շ���true�����򷵻�false
	bool Full();                 //�ж϶����Ƿ�Ϊ����������true�����򷵻�false
private:
    T data[QueueSize];           //��Ŷ���Ԫ�ص�����
    int front, rear;    //��ͷ�Ͷ�βָ�룬�ֱ�ָ���ͷԪ�����������ǰһ�±�Ͷ�βԪ�ص������±�
};

/*
 * ǰ�����������в�����
 * ��    �룺��
 * ��    �ܣ���ʼ������
 * ��    ������
 * ��������������һ���ն���
 */

template <class T>
CirQueue<T>::CirQueue( ) 
{
	front=rear=QueueSize-1;
} 

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ����ٶ���
 * ��    ������
 * �����������ͷŶ�����ռ�õĴ洢�ռ�
 */

template <class T>
CirQueue<T>::~CirQueue( )
{

}

/*
 * ǰ�������������Ѵ���
 * ��    �룺Ԫ��ֵx
 * ��    �ܣ��ڶ�β����һ��Ԫ��
 * ��    ����������벻�ɹ����׳��쳣
 * �����������������ɹ�����β������һ��Ԫ��
 */

template <class T> 
void CirQueue<T>::EnQueue(T x)
{
	if (Full()) throw "Overflow";
    rear=(rear+1) % QueueSize;   //��βָ����ѭ�������¼�1
    data[rear]=x;                //�ڶ�β������Ԫ��
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ�ɾ����ͷԪ��
 * ��    �������ɾ���ɹ������ر�ɾԪ��ֵ�������׳�ɾ���쳣
 * �������������ɾ���ɹ�����ͷ������һ��Ԫ��
 */

template <class T> 
T CirQueue<T>::DeQueue( )
{
    if (Empty()) throw "Downflow"; 
    front=(front+1) % QueueSize;    //��ͷָ����ѭ�������¼�1
    return data[front];             //��ȡ�����س���ǰ�Ķ�ͷԪ�أ�ע���ͷָ��
}
                                   //ָ���ͷԪ�ص�ǰһ��λ��
/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ���ȡ��ͷԪ��
 * ��    ���������в��գ����ض�ͷԪ��
 * �������������в���
 */

template <class T>
T CirQueue<T>::GetQueue( )
{   
    int i;
    if (Empty()) throw "Downflow"; 
    i=(front+1) % QueueSize;  //ע�ⲻҪ����ͷָ�븳ֵ
    return data[i];
}

/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ��ж϶����Ƿ�Ϊ��
 * ��    �����������Ϊ�գ�����1�����򣬷���0
 * �������������в���
 */

template <class T> 
bool CirQueue<T>::Empty( ) 
{
    return front==rear;
}
/*
 * ǰ�������������Ѵ���
 * ��    �룺��
 * ��    �ܣ��ж϶����Ƿ�Ϊ��
 * ��    �����������Ϊ��������1�����򣬷���0
 * �������������в���
 */

template <class T> 
bool CirQueue<T>::Full( ) 
{
    return (rear+1) % QueueSize ==front; 
}
int main()
{
	CirQueue<string> Q;
	string x;
	while(1){
		cin>>x;
        if(x=="#") break;
		try{
			cout<<"EnQueue:";
			Q.EnQueue(x);
			cout<<x<<"\n";
		}
		catch(const char *ms)
		{
			cout<<x<<" "<<ms<<endl;
		}

	}
	while(!Q.Empty())
	{
		x=Q.DeQueue();
		cout<<"DeQueue:"<<x<<endl;
	}
	try{
		x=Q.GetQueue();
	}
	catch(const char *ms)
	{
		cout<<"GetQueue:The queue is empty,"<<ms<<endl;
	}
	return 0;
}