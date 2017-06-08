//LinkList.cpp

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
	  Print(p->data);
	  p=p->next;
	}
	cout<<endl;
}