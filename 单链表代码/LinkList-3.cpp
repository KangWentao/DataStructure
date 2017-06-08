//LinkSortList-1 basic operations
#include <iostream>
using namespace std;
template <class T>
struct Node
{
  T data;
  Node<T> *next;  //�˴�<T>Ҳ����ʡ��
};

template <class T>
class LinkSortList
{
  public:
    LinkSortList( );  //����ֻ��ͷ���Ŀ�����
    ~LinkSortList();             //��������
 	void Insert(T x);        //sort insert
	int Length();
    void DispList( );           //������������������������Ԫ��
    void Merge(LinkSortList<T> &A, LinkSortList<T> &B);  //�ϲ�A,B����ǰ�� 
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
*ǰ����������
*��    �룺��
*��    �ܣ���
*��    ������
*������������
*/
template <class T>
LinkSortList<T>:: ~LinkSortList()
{  
	Node<T> *s;
	while (first){
        s=first;
		first=first->next;
        delete s;
    }
}


/*
*ǰ�����������������,��Ԫ�طǵݼ�����
*��    �룺����Ԫ��x
*��    �ܣ���Ԫ��x���뵽�����������λ��
*��    ������
*���������������������Ԫ�أ�������
*/
template <class T>  
void LinkSortList<T>::Insert(T x)
{  
   Node<T> *p; 
   p=first;     //����ָ��p��ʼ��
   while (p->next && p->next->data<=x)
        p=p->next;   //����ָ��p����
   Node<T> *s;
   s=new Node<T>; 
   s->data=x;  //���ڴ�����һ�����s����������Ϊx
   s->next=p->next;       //�����s���뵽���p֮��
   p->next=s;
}


//merge sorted list
  
template <class T>
void LinkSortList<T>::Merge(LinkSortList<T> &A, LinkSortList<T> &B){
	Node <T> *pa, *pb, *rear;
	pa=A.first->next;
	A.first->next=NULL;  
	pb=B.first->next;
	B.first->next=NULL;
	rear=first;
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
	LinkSortList <int> A,B,C;
	int x;
	while(1){
		cin>>x;
		if(!x) break;
		A.Insert(x);
	}
	while(1){
		cin>>x;
		if(!x) break;
		B.Insert(x);
	}
	A.DispList();
	B.DispList();
	C.Merge(A,B);
	C.DispList();
    A.DispList();
	B.DispList();
	return 0;	
}