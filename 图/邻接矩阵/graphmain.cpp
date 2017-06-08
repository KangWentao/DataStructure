#include <iostream>
#include <string>                   //引入标准库中的头文件
using namespace std;

//循环队列类
const int QueueSize=100;  //循环队列的最大长度
template <class T>        //定义模板类CirQueue
class CirQueue
{
public:
    CirQueue( );                 //构造函数，置空队
    ~ CirQueue( );               //析构函数
    void EnQueue(T x);           //将元素x入队
    T DeQueue( );                //将队头元素出队
    T GetQueue( );               //取队头元素（并不删除）
    bool Empty( );               //判断队列是否为空
	bool Full();
private:
    T data[QueueSize];  //存放队列元素的数组
    int front, rear;    //队头和队尾指针，分别指向队头元素的前一个位置和队尾元素的位置
};

//功    能：初始化空队列
 template <class T>
CirQueue<T>::CirQueue( ) 
{
	front=rear=0;
} 

// 功    能：销毁队列
template <class T>
CirQueue<T>::~CirQueue( )
{
}

//功    能：元素x入队
template <class T> 
void CirQueue<T>::EnQueue(T x)
{
    if (Full()) throw "Overflow";
    rear=(rear+1) % QueueSize;   //队尾指针在循环意义下加1
    data[rear]=x;                //在队尾处插入元素
}

//功    能：队头元素出队，返回值为出队元素
template <class T> 
T CirQueue<T>::DeQueue( )
{
    if (Empty()) throw "Downflow"; 
    front=(front+1) % QueueSize;    //队头指针在循环意义下加1
    return data[front];             //读取并返回出队前的队头元素，注意队头指针
}
                                   //指向队头元素的前一个位置
// 功    能：获取队头元素
template <class T>
T CirQueue<T>::GetQueue( )
{   
    int i;
    if (Empty()) throw "Downflow"; 
    i=(front+1) % QueueSize;  //注意不要给队头指针赋值
    return data[i];
}

// 功    能：判断队列是否为空,若空返回true，否则返回false
template <class T> 
bool CirQueue<T>::Empty( ) 
{
    return front==rear; 
}
//功   能：判断队列是否满，若满返回true，否则false
template <class T>
bool CirQueue<T>::Full()
{
	return (rear+1)%QueueSize==front;
}

//栈类
const int StackSize=100;  //100只是示例性的数据，可以根据实际问题具体定义
template <class T>       //定义模板类SeqStack
class SeqStack
{
public:
    SeqStack( ) ;            //构造函数，栈的初始化
	~SeqStack( );            //析构函数
    void Push(T x);          //将元素x入栈
    T Pop( );                //将栈顶元素弹出
    T GetTop( );	         //取栈顶元素（并不删除）
	bool Empty( );           //判断栈是否为空
	bool Full();             //判断栈是否为满
private:
    T data[StackSize];      //存放栈元素的数组
    int top;                //栈顶指针，指示栈顶元素在数组中的下标
};

//初始化空栈
template <class T>
SeqStack<T>::SeqStack( )
{
	top=-1;
}

//功    能：销毁栈
template <class T>
SeqStack<T>::~SeqStack( )
{
} 

//功    能：元素x压栈
template <class T> 
void SeqStack<T>::Push(T x)
{
    if (Full()) throw "Overflow";
    top++;
    data[top]=x;
}
// 功    能：栈顶元素弹栈
template <class T>
T SeqStack<T>::Pop( )
{ 
    T x;
    if (Empty()) throw "Downflow";
    x=data[top--];
    return x;
}

// 功    能：读取当前的栈顶元素
template <class T> 
T SeqStack<T>::GetTop( )
{
	if (Empty())throw"Downflow";  
    return data[top];
}

//功    能：判断栈是否为空
template <class T> 
bool SeqStack<T>::Empty( )
{
	return top==-1;
} 

//功    能：判断栈是否为满
template <class T> 
bool SeqStack<T>::Full( )
{
	return top==StackSize-1;
} 

//Class MGraph
const int MaxSize=20;               //图中最多顶点个数
int visited[MaxSize];                //访问标志数组     
template <class T>
class MGraph
{
public:
    MGraph(T a[],int n,int e);   //构造函数，初始化具有n个顶点,e条边的图
    void DispMGraph();           //输出图中顶点值和矩阵值               
    
	void DFSTraverse(int v);               //深度优先遍历图
	void BFSTraverse(int v);               //广度优先遍历图

private:
    T  vertex[MaxSize];             //存放图中顶点信息的数组
    int arc[MaxSize][MaxSize];      //存放图中顶点关系（边）的数组
    int vertexNum,arcNum;           //图的顶点数和边数
 };

//构造一个邻接矩阵存储的无向图
template <class T>
MGraph<T>::MGraph(T a[], int n, int e) 
{
	vertexNum=n;                 //顶点数
	arcNum=e;                    //边数
	int i,j,k;
	for (i=0; i<vertexNum; i++) 
		vertex[i]=a[i];          //顶点值
	for (i=0; i<vertexNum; i++)    //初始化邻接矩阵值为0（顶点间无边）
		for (j=0; j<vertexNum; j++)
			arc[i][j]=0;             
	for (k=0; k<arcNum; k++)   //依次输入e条边
	{
		cin>>i>>j;             //输入各条边依附的两个顶点的序号
		arc[i][j]=1;           //置有边标志
		arc[j][i]=1;    
	}
}

//输出图中所有顶点信息，和边信息
template <class T>
void MGraph<T>::DispMGraph( )             
{                                 
	int i,j;
    cout<<"  ";
    for(i=0;i<vertexNum;i++)             
		cout<<vertex[i]<<" ";//输出图中所有的顶点
    cout<<endl;
	for(i=0;i<vertexNum;i++)
	{
		cout<<vertex[i]<<" ";
		for(j=0;j<vertexNum;j++)
			cout<<arc[i][j]<<" ";  //输出边值（0/1）
		cout<<endl;
	}
}
//从v顶点出发深度优先遍历图（一个连通子图）
template <class T>
void MGraph<T>::DFSTraverse(int v)  //从v顶点出发深度优先遍历图（一个连通子图）
{
	cout<<vertex[v]<<" ";
	visited[v]=1;
	for(int i=0;i<vertexNum;i++)
		if(arc[v][i]==1&&!visited[i]) DFSTraverse(i);

}     

//从顶点v出发广度优先遍历图（一个连通子图）
template <class T>
void MGraph<T>::BFSTraverse(int v)    //从v顶点出发广优先遍历图（一个连通子图）
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
	string a[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N"}; //顶点信息
	int i,n,e;
	cin>>n>>e;  //输入顶点个数和边个数
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