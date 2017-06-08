//doubleDLinkList.cpp
#include <iostream>
#include <string>
using namespace std;

template <class T>
struct DNode
{
  T data;
  DNode<T> *prior, *next;  
};

template <class T>
class DLinkList
{
  public:
    DLinkList( );  //����ֻ��ͷ����˫��ѭ����������  
    ~DLinkList();        //��������
    int Length();        //������ĳ���
   	void Insert(T x);    //��β����x
	bool Judge( );       //�ж϶Գ�
    void DispListF( );   //����������������߼���������Ԫ��
	void DispListR( );   //��������������շ����߼���������Ԫ��
  
 private:
   DNode<T> *first;  //˫�������ͷָ��
};

/*
*ǰ����������������
*��    �룺��
*��    �ܣ�����һ��ֻ��ͷ����˫��ѭ������
*��    ������
*��������������һ������
*/
template <class T>
DLinkList<T>:: DLinkList( ){
	first=new DNode<T>; 
	first->next=first->prior=first;
}

/*
*ǰ���������������
*��    �룺��
*��    �ܣ��ͷ�������������ռ�ڴ浥Ԫ
*��    ������
*���������������㱻�ͷ�
*/
template <class T>
DLinkList<T>:: ~DLinkList()
{  
    DNode<T> *s;
	s=first->next;
	while (s!=first){
        first->next=s->next;
		delete s;
		s=first->next;
	}
	delete s;
}

/*
*ǰ���������������,
*��    �룺����Ԫ��x
*��    �ܣ���Ԫ��x���뵽�����βλ��
*��    ������
*�������������������Ԫ��
*/
template <class T>  
void DLinkList<T>::Insert(T x)
{  
   DNode<T> *s;
   s=new DNode<T>; 
   s->data=x;  //���ڴ�����һ�����s����������Ϊx
   s->next=first;       //�����s���뵽��β
   s->prior=first->prior;
   first->prior=s;
   s->prior->next=s;
}

//�жϵ�������Գƣ��ԳƷ���true�����򷵻�false
template <class T>
bool DLinkList<T>::Judge( ){
       DNode<T> *f, *r;
	   f=first->next;
	   r=first->prior;
       while (f!=r&& r->next!=f)
		   if (f->data!=r->data) 
			   return false;
		   else{
			   f=f->next;
			   r=r->prior;
		   }
	   return true;
}

/*
*ǰ�����������������
*��    �룺��
*��    �ܣ������������
*��    ������������
*������������������
*/
template <class T> 
int DLinkList<T>::Length( )
{
  DNode <T> *p = first->next;
  int count = 0;
  while(p!=first)
  { 
	  count++;
	  p = p->next;   
  }
  return count;
}

/*
*ǰ�����������������
*��    �룺��
*��    �ܣ����������
*��    �����������Ԫ��
*������������������
*/
template <class T> 
void DLinkList<T>::DispListF( )
{
	DNode<T> *p;
	cout<<"The length:"<<Length()<<endl;
	cout<<"The elements:\n";
	p=first->next;
	while (p!=first)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
	cout<<endl;
}/*
*ǰ�����������������
*��    �룺��
*��    �ܣ����������
*��    �����������Ԫ��
*������������������
*/
template <class T> 
void DLinkList<T>::DispListR( )
{
	DNode<T> *p;
	cout<<"The length:"<<Length()<<endl;
	cout<<"The elements:\n";
	p=first->prior;
	while (p!=first)
	{
	  cout<<p->data<<" ";
	  p=p->prior;
	}
	cout<<endl;
}
int main()
{
	DLinkList<string> DL;
	string subject;
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>subject;
		DL.Insert(subject);
	}
	DL.DispListF();
	DL.DispListR();
	return 0;
}

