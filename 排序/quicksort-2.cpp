#include<iostream>
using namespace std;
//ջ��
const int StackSize=100;  //10ֻ��ʾ���Ե����ݣ����Ը���ʵ��������嶨��
template <class T>       //����ģ����SeqStack
class SeqStack
{
public:
    SeqStack( ) ;            //���캯����ջ�ĳ�ʼ��
	~SeqStack( );            //��������
    void Push(T x);          //��Ԫ��x��ջ
    T Pop( );                //��ջ��Ԫ�ص���
    T GetTop( );	         //ȡջ��Ԫ�أ�����ɾ����
	bool Empty( );           //�ж�ջ�Ƿ�Ϊ��
	bool Full();             //�ж�ջ�Ƿ�Ϊ��
private:
    T data[StackSize];      //���ջԪ�ص�����
    int top;                //ջ��ָ�룬ָʾջ��Ԫ���������е��±�
};

//��ʼ����ջ
template <class T>
SeqStack<T>::SeqStack( )
{
	top=-1;
}

//��    �ܣ�����ջ
template <class T>
SeqStack<T>::~SeqStack( )
{
} 

//��    �ܣ�Ԫ��xѹջ
template <class T> 
void SeqStack<T>::Push(T x)
{
    if (Full()) throw "Overflow";
    top++;
    data[top]=x;
}
// ��    �ܣ�ջ��Ԫ�ص�ջ
template <class T>
T SeqStack<T>::Pop( )
{ 
    T x;
    if (Empty()) throw "Downflow";
    x=data[top--];
    return x;
}

// ��    �ܣ���ȡ��ǰ��ջ��Ԫ��
template <class T> 
T SeqStack<T>::GetTop( )
{
	if (Empty())throw"Downflow";  
    return data[top];
}

//��    �ܣ��ж�ջ�Ƿ�Ϊ��
template <class T> 
bool SeqStack<T>::Empty( )
{
	return top==-1;
} 

//��    �ܣ��ж�ջ�Ƿ�Ϊ��
template <class T> 
bool SeqStack<T>::Full( )
{
	return top==StackSize-1;
} 
//˳�����
const int MaxSize=100;
class List
{
private:
	int r[MaxSize+1];
	int n;
public:
    List(){n=0;} //empty list
	void InsertR(int k)  //��β����
	{  r[++n]=k;}
	void Display();      //display
	void QuickSort();   //quickSort
	void QuickSort2();
};

//��������
void List::QuickSort()
{
	SeqStack<int> S;
//	int first, int end;
	if(n>1){S.Push(n);S.Push(1);}
	while(!S.Empty())
	{
         //һ�λ���
		int first=S.Pop();//first;                        //��ʼ��
		int end=S.Pop();//end;
	//	if(first<end) {//�������}
		int i=first;
		int j=end;
		r[0]=r[i];
		while (i<j)	
		{  
			while (i<j && r[j]>=r[0])
				j--;                        //�Ҳ�ɨ��
			r[i]=r[j];                 //����С��¼������ǰ��
			while (i<j && r[i]<=r[0]) 
				i++;                         //���ɨ��
			r[j]=r[i]; //���ϴ��¼����������	  
		}
		r[i]=r[0];
		if(i+1<end)
		{
			S.Push(end);
			S.Push(i+1);
		}
		if(first<i-1)
		{
			S.Push(i-1);
			S.Push(first);
		}
	}
}
void List::QuickSort2()
{
	SeqStack<int> S;
//	int first, int end;
	S.Push(n);S.Push(1);
	while(!S.Empty())
	{
		//һ�λ���
		int first=S.Pop();//first;                        //��ʼ��
		int end=S.Pop();//end;
		if(first<end) 
		{//�������
			int i=first;
			int j=end;
			r[0]=r[i];
			while (i<j)	
			{  
				while (i<j && r[j]>=r[0])
					j--;                        //�Ҳ�ɨ��
				r[i]=r[j];                 //����С��¼������ǰ��
				while (i<j && r[i]<=r[0]) 
					i++;                         //���ɨ��
				r[j]=r[i]; //���ϴ��¼����������	  
			}
			r[i]=r[0];
			S.Push(end);
			S.Push(i+1);
			S.Push(i-1);
			S.Push(first);
		}
	}
}
void List::Display()
{
	for(int i=1;i<=n;i++)
       cout<<r[i]<<" ";	  
	cout<<"\n";
}
int main()
{
	List L;
	while(1)
	{
		int k;
		cin>>k;
		if(!k) break;
        L.InsertR(k);
	}
	L.Display();
	L.QuickSort();
	L.Display();
	return 0;
}

/*
12 21 32 2 4 24 21 432 23 9 0
12 21 32 2 4 24 21 432 23 9 
2 4 9 12 21 21 23 24 32 432 

12 21 32 2 4 24 21 432 23 9 88 76 35 0
12 21 32 2 4 24 21 432 23 9 88 76 35 
2 4 9 12 21 21 23 24 32 35 76 88 432 

  */