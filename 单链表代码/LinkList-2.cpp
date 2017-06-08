//LinkList-1 basic operations
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
    LinkList(T a[ ], int n);  //������n��Ԫ�صĵ�����
    ~LinkList();             //��������
    int Length();          //������ĳ���
    T Get(int i);           //ȡ�������е�i������Ԫ��ֵ
    int Locate(T x);       //��������ֵΪx��Ԫ�����
    void Insert(int i, T x);   //�ڵ������е�i��λ�ò���Ԫ��ֵΪx�Ľ��
	void Insert(T x);        //sort insert
	void Exchange( );        //exchange list
    T Delete(int i);        //�ڵ�������ɾ����i�����
    void DispList( );           //������������������������Ԫ��
    friend void Divide(LinkList<T> &La, LinkList<T> &Lb);
    friend void Merge(LinkList<T> &La, LinkList<T> Lb);
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
LinkList<T>:: ~LinkList()
{
}

/*
*ǰ�����������������
*��    �룺��ѯԪ��λ��i
*��    �ܣ���λ����λ��Ϊi��Ԫ�ز����ֵ
*��    ������ѯԪ�ص�ֵ
*������������������
*/
template <class T>
T LinkList<T>::Get(int i){   
	Node<T> *p;
	int j;
    p=first;  
	j=0;  
	while (p && j<i){
		p=p->next;       //����ָ��p����
        j++;
	}
    if (!p) throw "λ�÷Ƿ�";
    else return p->data;
}

/*
*ǰ�����������������
*��    �룺��ѯԪ��ֵx
*��    �ܣ���ֵ����ֵ��Ԫ�ز����λ��
*��    ������ѯԪ�ص�λ��
*������������������
*/
template <class T> 
int LinkList<T>::Locate(T x){
	Node<T> *p; 
	int j;
	p=first->next;
	j=0;
	while(p){
		j++;
		if (p->data==x)return j;
		p=p->next;
	    
	}
	throw "�����޸�Ԫ��";	
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
*ǰ�����������������,��Ԫ�طǵݼ�����
*��    �룺����Ԫ��x
*��    �ܣ���Ԫ��x���뵽�����������λ��
*��    ������
*���������������������Ԫ�أ�������
*/
template <class T>  
void LinkList<T>::Insert(T x)
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

//������������
template <class T>
void LinkList<T>::Exchange( ){
       Node<T> *p, *q;
	   p=first->next; 
       first->next=NULL;
       while (p){
            q=p->next;
            p->next=first->next;
            first->next=p;
            p=q;
       }
}

//divide
template <class T>
void Divide(LinkList<T> &La, LinkList<T> &Lb){
	Node <T> *p,*q;
	p=La.first;
	while(p->next)
		if (p->next->data%2==1)
			p=p->next;
		else {
			q=p->next;
			p->next=q->next; 
			q->next=Lb.first->next; //Lb.Insert(1,q->data);
			Lb.first->next=q;            // delete q;
		}
}   

//merge sorted list
  
template <class T>
void Merge(LinkList<T> &La, LinkList<T> Lb){
	Node <T> *pa, *pb, *rear;
	pa=La.first->next;
	La.first->next=NULL;  
	pb=Lb.first->next; 
	rear=La.first;
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
*��    �ܣ������������
*��    ������������
*������������������
*/
template <class T> 
int LinkList<T>::Length( )
{
  Node <T> *p = first->next;
  int i = 0;
  while(p)
  { i++;
    p = p->next;
   
  }
  return i;
}
/*
*ǰ�����������������
*��    �룺Ҫɾ��Ԫ��λ��i
*��    �ܣ�ɾ����������λ��Ϊi��Ԫ��
*��    ������
*����������������ɾ��Ԫ��
*/
template <class T>  
T LinkList<T>::Delete(int i)
{ 
  Node<T> *p; int j;
  p=first ; j=0;  //����ָ��p��ʼ��
  while (p && j<i-1)  //���ҵ�i-1�����
  {
    p=p->next;
    j++;
  }
  if (!p || !p->next) throw "λ��";  //���p�����ڻ���p�ĺ�̽�㲻����
    else {
		  Node<T> *q; int x;
          q=p->next; x=q->data;  //�ݴ汻ɾ���
          p->next=q->next;  //ժ��
          delete q; 
          return x;
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
	cout<<"The elements: ";
	p=first->next;
	while (p)
	{
	  cout<<p->data<<" ";
	  p=p->next;
	}
	cout<<endl;
}
void main( ){
	int i,choi;
	int x;
        LinkList <int> A; //normal list1   
	
	do{
		cout<<"\n 0 exit       1 Insert       2 Delete \n";
		cout<<" 3 Get(i)     4  Locate(x)   5 Exchange\n";
		cout<<" 6 Divide     7  DispList"<<endl;
		cout<<" 8 Create a sorted list, then display\n";
		cout<<" please choice..."<<endl;
		cin>>choi;		
		try{
			switch(choi){
			case 0:
				break;
			case 1:	
                cout<<"Input the position and an element\n";
				cin>>i>>x;
				A.Insert(i,x);			
				break;
			case 2:
				cout<<"Input the position of the deleted element\n";
				cin>>i;
				A.Delete(i);
				break;
			case 3:
                cout<<"Input the position of the searched element\n";
				cin>>i;
				x=A.Get(i);
				cout<<"Element of i:"<<x<<endl;
				break;
			case 4:
                cout<<"Input the located element\n";
				cin>>x;
				i=A.Locate(x);
				cout<<"Position of x: "<<i<<endl;
				break;
			case 5:
				A.Exchange();
				break;
			case 6:
				{
					LinkList <int> B;
					Divide(A,B);
					A.DispList();
					B.DispList();
				}
				break;
			case 7:
				A.DispList();
				break;
			case 8:
				{
					LinkList<int> B, C;
					cout<<"Input 5 data(int): ";
					for (i=1;i<=5;i++){
						cin>>x;
						B.Insert(x);
					}
					B.DispList();
					cout<<"Input 5 data(int): ";
					for (i=1;i<=5;i++){
						cin>>x;
						C.Insert(x);
					}
					C.DispList();
					Merge(B,C);
					B.DispList();
				}
				break;
				
			default:
				throw "Choice error";
			}
		}
		catch(char *wrong){
			cout<<wrong<<endl;
		}
	}while(choi);
}