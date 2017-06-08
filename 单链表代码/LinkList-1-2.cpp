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
    ~LinkList();             //��������
    int Length();          //������ĳ���
    int Locate(T x);       //��������ֵΪx��Ԫ�����
    void Insert(int i, T x);   //�ڵ������е�i��λ�ò���Ԫ��ֵΪx�Ľ��
	void Reverse( );        //reverse list
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
	int count=0;
	for(p=first->next;p;p=p->next)
	{
		count++;
		if (p->data==x) break;
	}
	if(p) return count;	
	else return 0;
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
   Node<T> *p; 
   int count;    
   //Locate position i-1
   count=0;   
   for(p=first;p->next;p=p->next)
   {
	   if (count>=i-1)break;
	   count++;
   }
   if (i<1||count<i-1) throw "Illegal inserted position";
   else { 
	  Node<T> *s;
      s=new Node<T>; 
	  s->data=x;    //���ڴ�����һ�����s����������Ϊx
      s->next=p->next;  //�����s���뵽���p֮��
      p->next=s;
	}
}


//������������
template <class T>
void LinkList<T>::Reverse( ){
       Node<T> *p, *s;
	   p=first->next; 
       first->next=NULL;
       while (p){
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
  for(p=first->next;p;p=p->next)
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
	for(p=first->next;p;p=p->next)
		cout<<p->data<<" ";
	cout<<endl;
}
int main( ){
	LinkList<int> sa;
	int x;
	int i=1;
	while(1)
	{
		cin>>x;
        if(!x)break;
		try{
			sa.Insert(i++,x);
		}
		catch(char *ms)
		{
			cout<<ms<<endl;
		}
	}
    
	cin>>x;
	sa.DispList();
	int pos=sa.Locate(x);
	if(!pos) cout<<"No found\n";
	else
		cout<<"Found position:"<<pos<<endl;	
	sa.Reverse();
	sa.DispList();
	return 0;
}