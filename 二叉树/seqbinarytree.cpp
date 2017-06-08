#include<iostream>
#include<cstring>
using namespace std;
//ѭ��������
const int QueueSize=100;  //ѭ�����е���󳤶�
template <class T>        //����ģ����CirQueue
class CirQueue
{
public:
    CirQueue( );                 //���캯�����ÿն�
    ~ CirQueue( );               //��������
    void EnQueue(T x);           //��Ԫ��x���
    T DeQueue( );                //����ͷԪ�س���
    T GetQueue( );               //ȡ��ͷԪ�أ�����ɾ����
    bool Empty( );               //�ж϶����Ƿ�Ϊ��
	bool Full();
private:
    T data[QueueSize];           //��Ŷ���Ԫ�ص�����
    int front, rear;    //��ͷ�Ͷ�βָ�룬�ֱ�ָ���ͷԪ�ص�ǰһ��λ�úͶ�βԪ�ص�λ��
};


 //��    �ܣ���ʼ���ն���
 template <class T>
CirQueue<T>::CirQueue( ) 
{
	front=rear=0;
} 

// ��    �ܣ����ٶ���
template <class T>
CirQueue<T>::~CirQueue( )
{
}

//��    �ܣ�Ԫ��x���
template <class T> 
void CirQueue<T>::EnQueue(T x)
{
    if (Full()) throw "Overflow";
    rear=(rear+1) % QueueSize;   //��βָ����ѭ�������¼�1
    data[rear]=x;                //�ڶ�β������Ԫ��
}

//��    �ܣ���ͷԪ�س��ӣ�����ֵΪ����Ԫ��
template <class T> 
T CirQueue<T>::DeQueue( )
{
    if (Empty()) throw "Downflow"; 
    front=(front+1) % QueueSize;    //��ͷָ����ѭ�������¼�1
    return data[front];             //��ȡ�����س���ǰ�Ķ�ͷԪ�أ�ע���ͷָ��
}
                                   //ָ���ͷԪ�ص�ǰһ��λ��
// ��    �ܣ���ȡ��ͷԪ��
template <class T>
T CirQueue<T>::GetQueue( )
{   
    int i;
    if (Empty()) throw "Downflow"; 
    i=(front+1) % QueueSize;  //ע�ⲻҪ����ͷָ�븳ֵ
    return data[i];
}

// ��    �ܣ��ж϶����Ƿ�Ϊ��,���շ���true�����򷵻�false
template <class T> 
bool CirQueue<T>::Empty( ) 
{
    return front==rear; 
}
//��   �ܣ��ж϶����Ƿ�������������true������false
template <class T>
bool CirQueue<T>::Full()
{
	return (rear+1)%QueueSize==front;
}

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
	if(top==-1) return 1;
	else return 0;
} 

//��    �ܣ��ж�ջ�Ƿ�Ϊ��
template <class T> 
bool SeqStack<T>::Full( )
{
	return top==StackSize-1;
} 


//˳���������
const int TreeSize=100;  //��󳤶�
template <class T>
class BiTree{
public:               
	BiTree(T *); //���캯������ʼ��һ�ö���������ǰ�������ɼ�������
    void PreOrder(int pos);     //ǰ�����������
    void InOrder(int pos);      //�������������
    void PostOrder(int pos);    //�������������
    int CountLeaf(int pos);     //����Ҷ�ӽ������
	int Depth(int pos);         //����߶�
	void PreOrder();            //�ǵݹ��������  
	void LevelOrder();          //��α���
private:
    T data[TreeSize];  //�洢����Ԫ��ֵ����0�±꿪ʼ
};

//constructor
template <class T>
BiTree<T>::BiTree(T *str)
{
	strcpy(data,str);
}

//�ǵݹ�ʵ��ǰ�����������
template <class T>
void BiTree<T>::PreOrder() {
     SeqStack <int> S; //ջ��ʼ�� 
	 int x;
     if(data[0]!='#') S.Push(0);
     while (!S.Empty( )) {
         x=S.Pop( );
         cout<<data[x]<<" ";
         if (data[2*x+2]!='#')  
			 S.Push(2*x+2);
         if (data[2*x+1]!='#')  
			 S.Push(2*x+1);
     }
}


//ǰ������������ĵݹ��㷨
template<class T>
void BiTree<T>::PreOrder(int pos)
{
	if(data[pos]=='#')  return;
	else{		
		cout<<data[pos]<<" ";
        PreOrder(2*pos+1);
		PreOrder(2*pos+2);
	}
}
//�������
template <class T>
void BiTree<T>::InOrder (int pos)
{
    if(data[pos]=='#')  return;
	else{		
		InOrder(2*pos+1);
		cout<<data[pos]<<" ";
		InOrder(2*pos+2);
	}
}

//�������
template <class T>
void BiTree<T>::PostOrder(int pos)
{ 
    if(data[pos]=='#')  return;
	else{		
		PostOrder(2*pos+1);
		PostOrder(2*pos+2);
		cout<<data[pos]<<" ";
	}
}

//��α���
template <class T>
void BiTree<T>::LevelOrder()
{
	CirQueue <int> Q; //����˳����У����ٶ����ᷢ������
    int x;
    if (data[0]!='#') 
	{
		Q.EnQueue(0);
		while (!Q.Empty()){
			x=Q.DeQueue();
     		cout<<data[x]<<" "; 		
    		if (data[2*x+1]!='#')  
				Q.EnQueue(2*x+1);
            if (data[2*x+2]!='#')
				Q.EnQueue(2*x+2);
		}
	}
}

//�������Ҷ�Ӹ���
template <class T>
int BiTree<T>::CountLeaf(int pos)
{
    if (data[pos]=='#')  return 0;
    else 
		if (data[2*pos+1]=='#'&&data[2*pos+2]=='#')
			return 1;
		else 
			return CountLeaf(2*pos+1)+CountLeaf(2*pos+2);
}
//��������߶�
template <class T>
int BiTree<T>::Depth(int pos)
{   int rl,rh;
    if (data[pos]=='#') return 0;
    else 
	{
		rl=Depth(2*pos+1);
	    rh=Depth(2*pos+2);
		if(rl>rh) return rl+1;
		else return rh+1;
	}
}

int main()
{
	char str[80];
	cin>>str;
	BiTree<char> bt(str);
	bt.PreOrder(0);
	cout<<endl;
	bt.InOrder(0);
	cout<<endl;
	bt.PostOrder(0);
	cout<<endl;
	bt.PreOrder();
	cout<<endl;
	bt.LevelOrder();
	cout<<endl;
	cout<<bt.CountLeaf(0)<<" "<<bt.Depth(0)<<endl;
	return 0;
}

/*
ab##c######
a b c 
b c a 
c b a 
a b c 
a b c 
1 3
*/

/*
abd#c####ef############
a b c e f d 
b e c f a d 
e f c b d a 
a b c e f d 
a b d c e f 
3 4
*/

/*
ABD#C####EF############
A B C E F D 
B E C F A D 
E F C B D A 
A B C E F D 
A B D C E F 
3 4
*/