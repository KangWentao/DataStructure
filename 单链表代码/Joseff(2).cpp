//Joseff
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
    LinkList( );  //����û��ͷ���Ŀ�����
    ~LinkList();  //��������
	void RInsert(T x);   //�������β����Ԫ��x
	void Create(int n);  //����RInsert��������βָ��ĵ���ѭ������������ͷ��㣩
	void Joseff(int m);
    void DispList( );     //������������������������Ԫ��
 private:
   Node<T> *rear;  //βָ��
};

//�����յ�ѭ����
template <class T>
LinkList<T>:: LinkList( ){
	rear=NULL;
}


//�����������ͷ���������ռ�ڴ浥Ԫ
template <class T>  
LinkList<T>:: ~LinkList( ){   
    Node<T> *s;
	if(rear) //����ǿ�����
	{
		s=rear->next;
		while (s!=rear){
			rear->next=s->next;
			delete s;
			s=rear->next;
		}
		delete s;
	}
}


//����n�����ݵ�����
template <class T>  
void LinkList<T>::Create(int n){   
    int i;
	for(i=1;i<=n;i++)
		RInsert(i);
}
//Joseff
template <class T>  
void LinkList<T>::Joseff(int m){   
    int i;
	Node<T> *s;
	while(rear!=rear->next)
	{
		for(i=1;i<m;i++)
			rear=rear->next;
		s=rear->next;
		cout<<s->data<<" ";
		rear->next=s->next;
	}
	cout<<rear->data<<" "<<endl;	
}
/*
*ǰ�����������������
*��    �룺����Ԫ��x,
*��    �ܣ���Ԫ��x���뵽�����βλ��
*��    ������
*���������������������Ԫ��
*/
template <class T>  
void LinkList<T>::RInsert(T x)
{  
   Node<T> *s;
   s=new Node<T>; 
   s->data=x;    //���ڴ�����һ�����s����������Ϊx
   if(rear)
   {
	   s->next=rear->next;  //�����s���뵽���rear֮��
	   rear->next=s;
	   rear=s;
   }
   else {
	   rear=s;
	   rear->next=rear;
   }
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
	if(rear)  //����ǿ��������
	{
		for(p=rear->next;p!=rear;p=p->next)
			cout<<p->data<<" ";
		cout<<p->data<<" ";
	}
	cout<<endl;
}
int main( ){
	LinkList<int> sa;
	int m,n;
	cin>>n>>m;
	sa.Create(n);  //����n���ˣ����1~n��������
   	sa.DispList(); // ��������������
	sa.Joseff(m);  // �����Ȧ�˵ı�Ŵ���
	return 0;
}