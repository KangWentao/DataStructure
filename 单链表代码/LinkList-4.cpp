//LinkList-4 divide into A and B
#include <iostream>
using namespace std;
template <class T>
struct Node
{
  T data;
  Node<T> *next;  //�˴�<T>Ҳ����ʡ��
};

template <class T>
class LinkList
{
  public:
    LinkList( );  //����ֻ��ͷ���Ŀ�����
    ~LinkList();             //��������
    int Length();          //������ĳ���
    void Insert(int i, T x);   //�ڵ������е�i��λ�ò���Ԫ��ֵΪx�Ľ��
    void Divide(LinkList<T> &A,LinkList<T> &B); //����ǰ����ֽ�ΪA��B��
    void DispList( );           //������������������������Ԫ��
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
LinkList<T>:: ~LinkList( ){   
    Node<T> *s;
	while (first){
        s=first;
		first=first->next;
        delete s;
    }
}

//����ǰ����ֽ�ΪA��B��
template<class T>
void LinkList<T>::Divide(LinkList<T> &A,LinkList<T> &B)
{
	Node<T>*p,*s;
	p=first->next;
	first->next=NULL;
	while(p)
	{
		if (p->data%2) {
			s=p;
			p=p->next;
			s->next=A.first->next;
			A.first->next=s;
		}
		else{	
			s=p;
			p=p->next;
			s->next=B.first->next;
			B.first->next=s;
		}
	}
}
/*
*ǰ�����������������
*��    �룺����Ԫ��x,����λ��i
*��    �ܣ���Ԫ��x���뵽��������λ��i��
*��    ������
*���������������������Ԫ��
*/
template <class T>  
void LinkList<T>::Insert(int i, T x)
{  
   Node<T> *p; int j;
   p=first; j=0;    //����ָ��p��ʼ��
   while (p && j<i-1)
   {
     p=p->next;   //����ָ��p����
     j++;
   }
   if (!p) throw "����λ�÷Ƿ�";
    else { 
	  Node<T> *s;
      s=new Node<T>; 
	  s->data=x;  //���ڴ�����һ�����s����������Ϊx
      s->next=p->next;       //�����s���뵽���p֮��
      p->next=s;
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
  Node <T> *p = first->next;
  int count = 0;
  while(p)
  { count++;
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
void LinkList<T>::DispList( )
{
	Node<T> *p;
	cout<<"The length:"<<Length()<<endl;
	cout<<"The elements:\n";
	p=first->next;
	while (p)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
	cout<<endl;
}
int main( ){
	LinkList<int> A,B,C;
	int x,i=1;
	while(1)
	{
		cin>>x;
        if(!x)break;
		try{
			C.Insert(i++,x);
		}
		catch(char *ms)
		{
			cout<<ms<<endl;
		}
	}    
	C.DispList();
	C.Divide(A,B);
	C.DispList();
	A.DispList();
	B.DispList();
	return 0;
}
/*
23 2 42 4 1121 27 40 0
The length:7
The elements:
23 2 42 4 1121 27 40 
The length:0
The elements:

The length:3
The elements:
27 1121 23 
The length:4
The elements:
40 4 42 2 
*/
