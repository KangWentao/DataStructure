#include <iostream>
#include <string>                   //�����׼���е�ͷ�ļ�
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
    T data[QueueSize];  //��Ŷ���Ԫ�ص�����
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
const int StackSize=100;  //100ֻ��ʾ���Ե����ݣ����Ը���ʵ��������嶨��
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

//Class MGraph
const int MaxSize=20;               //ͼ����ඥ�����
int visited[MaxSize];                //���ʱ�־����     
template <class T>
class MGraph
{
public:
    MGraph(T a[],int n,int e);   //���캯������ʼ������n������,e���ߵ�ͼ
    void DispMGraph();           //���ͼ�ж���ֵ�;���ֵ               
    
	void DFSTraverse(int v);               //������ȱ���ͼ
	void BFSTraverse(int v);               //������ȱ���ͼ

private:
    T  vertex[MaxSize];             //���ͼ�ж�����Ϣ������
    int arc[MaxSize][MaxSize];      //���ͼ�ж����ϵ���ߣ�������
    int vertexNum,arcNum;           //ͼ�Ķ������ͱ���
 };

//����һ���ڽӾ���洢������ͼ
template <class T>
MGraph<T>::MGraph(T a[], int n, int e) 
{
	vertexNum=n;                 //������
	arcNum=e;                    //����
	int i,j,k;
	for (i=0; i<vertexNum; i++) 
		vertex[i]=a[i];          //����ֵ
	for (i=0; i<vertexNum; i++)    //��ʼ���ڽӾ���ֵΪ0��������ޱߣ�
		for (j=0; j<vertexNum; j++)
			arc[i][j]=0;             
	for (k=0; k<arcNum; k++)   //��������e����
	{
		cin>>i>>j;             //���������������������������
		arc[i][j]=1;           //���б߱�־
		arc[j][i]=1;    
	}
}

//���ͼ�����ж�����Ϣ���ͱ���Ϣ
template <class T>
void MGraph<T>::DispMGraph( )             
{                                 
	int i,j;
    cout<<"  ";
    for(i=0;i<vertexNum;i++)             
		cout<<vertex[i]<<" ";//���ͼ�����еĶ���
    cout<<endl;
	for(i=0;i<vertexNum;i++)
	{
		cout<<vertex[i]<<" ";
		for(j=0;j<vertexNum;j++)
			cout<<arc[i][j]<<" ";  //�����ֵ��0/1��
		cout<<endl;
	}
}
//��v�������������ȱ���ͼ��һ����ͨ��ͼ��
template <class T>
void MGraph<T>::DFSTraverse(int v)  //��v�������������ȱ���ͼ��һ����ͨ��ͼ��
{
	cout<<vertex[v]<<" ";
	visited[v]=1;
	for(int i=0;i<vertexNum;i++)
		if(arc[v][i]==1&&!visited[i]) DFSTraverse(i);

}     

//�Ӷ���v����������ȱ���ͼ��һ����ͨ��ͼ��
template <class T>
void MGraph<T>::BFSTraverse(int v)    //��v������������ȱ���ͼ��һ����ͨ��ͼ��
{
	CirQueue<int> Q;
	int i;
	cout<<vertex[v]<<" ";
	visited[v]=1;
	Q.EnQueue(v);
	while(!Q.Empty())
	{
		v=Q.DeQueue();
		for(i=0;i<vertexNum;i++)
			if(arc[v][i]==1&&visited[i]==0)
			{
				cout<<vertex[i]<<" ";
				visited[i]=1;
				Q.EnQueue(i);
			}
	} 
}

int main()
{
	string a[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N"}; //������Ϣ
	int i,n,e;
	cin>>n>>e;  //���붥������ͱ߸���
    MGraph<string> G(a,n,e);
	G.DispMGraph();
	for(i=0;i<n;i++)
		visited[i]=0;
	cout<<"DFS:";
	G.DFSTraverse(0);
	cout<<endl;
    for(i=0;i<n;i++)
		visited[i]=0;
	cout<<"BFS:";
	G.BFSTraverse(0);
	return 0;
}
 
/*
6 7
0 1 0 3 1 2 1 5 2 4 3 5 4 5
  A B C D E F 
A 0 1 0 1 0 0 
B 1 0 1 0 0 1 
C 0 1 0 0 1 0 
D 1 0 0 0 0 1 
E 0 0 1 0 0 1 
F 0 1 0 1 1 0 
DFS:A B C E F D 
BFS:A B D C F E 

*/