//circular linklist
#include <iostream>
using namespace std;
//���ṹ
template <class T>
struct Node
{
  T data;
  Node<T> *next;  
};
//����ѭ��������
template <class T>
class LinkList
{
  public:
    LinkList( );  //����ֻ��ͷ���Ŀ�����
    ~LinkList();  //��������
    int Length();    //������ĳ���
    void Insert(T x);   //�ڵ������еı�βλ�ò���Ԫ��ֵΪx�Ľ��
	void Reverse( );      //��������
    void DispList( );     //������������������������Ԫ��
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
LinkList<T>:: LinkList( ){
	first=new Node<T>; 
	first->next=first;
}


/*
*ǰ���������������
*��    �룺��
*��    �ܣ��ͷ�������������ռ�ڴ浥Ԫ
*��    ������
*���������������㱻�ͷ�
*/
template <class T>  
LinkList<T>:: ~LinkList( ){   
    Node<T> *s;
	s=first->next;
	while (s!=first){
        first->next=s->next;
		delete s;
		s=first->next;
	}
	delete s;
}


/*
*ǰ�����������������
*��    �룺����Ԫ��x,
*��    �ܣ���Ԫ��x���뵽�����βλ��
*��    ������
*���������������������Ԫ��
*/
template <class T>  
void LinkList<T>::Insert(T x)
{  
   Node<T> *rear;    
   //Locate position 
    
   for(rear=first;rear->next!=first;rear=rear->next);
   Node<T> *s;
   s=new Node<T>; 
   s->data=x;    //���ڴ�����һ�����s����������Ϊx
   s->next=rear->next;  //�����s���뵽���rear֮��
   rear->next=s;
}


//������������
template <class T>
void LinkList<T>::Reverse( ){
       Node<T> *p, *s;
	   p=first->next; 
       first->next=first;
       while (p!=first){
            s=p;
			p=p->next;
            s->next=first->next;
            first->next=s;
       }
}

/*
*ǰ�����������������
*��    �룺��
*��    �ܣ������������
*��    ������������
*������������������
*/
template <class T> 
int LinkList<T>::Length( )
{
  Node <T> *p;
  int count=0;
  for(p=first->next;p!=first;p=p->next)
	  count++;
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
void LinkList<T>::DispList( )
{
	Node<T> *p;
	cout<<"The length:"<<Length()<<endl;
	cout<<"The elements:\n";
	for(p=first->next;p!=first;p=p->next)
		cout<<p->data<<" ";
	cout<<endl;
}
int main( ){
	LinkList<int> sa;
	int x;
	while(1)
	{
		cin>>x;
        if(!x)break;
		sa.Insert(x);		
	}
   	sa.DispList();
	sa.Reverse();
	sa.DispList();
	return 0;
}