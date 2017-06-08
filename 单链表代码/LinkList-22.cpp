//LinkSortList
#include <iostream>
using namespace std;
template <class T>
struct Node
{
  T data;
  Node<T> *next;  //�˴�<T>Ҳ����ʡ��
};
//����������
template <class T>
class LinkSortList
{
  public:
    LinkSortList( );  //����ֻ��ͷ���Ŀ�����
    ~LinkSortList();             //��������
    void Insert(T x);   //�����������в���Ԫ��xʹ����������
    int Length();      //���
    int DeleteOdd();     //�ڵ�������ɾ����������������ֵΪ��������
    void DispList( );     //��������������������������Ԫ��
 private:
   Node<T> *first;  //�������ͷָ��
};
/*
*ǰ������������������
*��    �룺��
*��    �ܣ�����һ��������
*��    ������
*��������������һ��������
*/
template <class T>
LinkSortList<T>:: LinkSortList( ){
	first=new Node<T>; 
	first->next=NULL;
}


/*
*ǰ����������
*��    �룺��
*��    �ܣ���
*��    ������
*������������
*/
template <class T>  
LinkSortList<T>:: ~LinkSortList( ){   
    Node<T> *s;
	while (first){
        s=first;
		first=first->next;
        delete s;
    }
}


/*
*ǰ�����������������
*��    �룺����Ԫ��x,ʹ����������
*��    �ܣ���Ԫ��x���뵽�����������λ��
*��    ������
*���������������������Ԫ��
*/
template <class T>  
void LinkSortList<T>::Insert(T x)
{  
   Node<T> *p; 
   p=first; //����ָ��p��ʼ��
   while (p->next && p->next->data<x)
	   p=p->next;   //����ָ��p����
   
   Node<T> *s;
   s=new Node<T>; 
   s->data=x;  //���ڴ�����һ�����s����������Ϊx
   s->next=p->next;       //�����s���뵽���p֮��
   p->next=s;
	
}


/*
*ǰ�����������������
*��    �룺��
*��    �ܣ�ɾ���������������������
*��    ������
*����������������ɾ��Ԫ��
*/
template <class T>  
int LinkSortList<T>::DeleteOdd()
{ 
  Node<T> *p,*s; 
  int count=0;
  p=first ;  //����ָ��p��ʼ��
  while (p->next) 
    if(p->next->data%2)
	{
		s=p->next;
		p->next=s->next;
		delete s;
		count++;
	}
	else 
		p=p->next;
	return count;
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
*ǰ�����������������
*��    �룺��
*��    �ܣ����������
*��    �����������Ԫ��
*������������������
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
	LinkSortList<int> sa;
	int x;
	while(1)
	{
		cin>>x;
        if(!x)break;
		sa.Insert(x);		
	}
    sa.DispList();
	int count=sa.DeleteOdd();
	cout<<"Count of deleted odds:"<<count<<endl;
	sa.DispList();
	return 0;
} 