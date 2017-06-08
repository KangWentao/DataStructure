//graphmain.cpp
#include <iostream>
#include <string>
using namespace std;
//栈类
const int StackSize=100;  //10只是示例性的数据，可以根据实际问题具体定义
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
	if(top==-1) return 1;
	else return 0;
} 

//功    能：判断栈是否为满
template <class T> 
bool SeqStack<T>::Full( )
{
	return top==StackSize-1;
} 
//图
const int MaxSize=20;     // 顶点个数的最大值
int visited[MaxSize];     //访问标志数组（0表示未访问，1表示已访问）

//定义边表结点
struct ArcNode                 
{
	int adjvex;                    //邻接点的序号
	ArcNode *next;                 //指向下一个边结点的指针
};

 //定义顶点表结点
template <class T>
struct VertexNode              
{
	int in;     //各顶点的入度
	T vertex;                 //顶点的名称
	ArcNode *firstedge;        //指向第一个边表结点的头指针
};

//邻接表类
template <class T>
class ALGraph
{
public:
   ALGraph(T a[ ], int n, int e);   //构造函数，初始化一个有n个顶点e条边的图
   ~ALGraph();                      //析构函数，释放邻接表中各边表结点的存储空间
   void DispALGraph();              //输出邻接表
   void CountInD();     //计算各个顶点的入度,存储在adjlist[i].in中
   void DispInD();     //输出各顶点的入度
   void TopSort();     //拓扑排序
private:
   VertexNode<T> adjlist[MaxSize];  //存放顶点表的数组
   int vertexNum, arcNum;           //图的顶点数和边数
};

/*
 *前置条件：图不存在
 *输    入：无 
 *功    能：图的初始化
 *输    出：无
 *后置条件：得到一个无向图
 */
template <class T>
ALGraph<T>::ALGraph(T a[ ], int n, int e)
{
    arcNum = e;                             //边数
	vertexNum=n;                            //顶点数
    int i,j;
	for (i=0; i<vertexNum; i++)
	{        
	   adjlist[i].vertex = a[i];
	   adjlist[i].firstedge = NULL;	    
	}

	for (int k=0; k<arcNum; k++)    //依次输入每一条边，并在相应边表中插入结点
    { 
		cin>>i>>j;                         //输入边所依附的两个顶点的序号
        ArcNode *s=new ArcNode; 
		s->adjvex=j;  //生成一个边表结点s
	    s->next=adjlist[i].firstedge;      //将结点s插入到i号表的头结点之后  
        adjlist[i].firstedge=s;
	}
}
/*   前置条件：图已存在
 *   输    入：无 
 *   功    能：销毁图
 *   输    出：无
 *   后置条件：释放图所占用的存储空间
 */
template <class T>
ALGraph<T>::~ALGraph( )
{
  for (int i=0; i<vertexNum; i++)
  {
    ArcNode * p=adjlist[i].firstedge;
	while (p!=NULL)                                              //循环删除
	{
		adjlist[i].firstedge=p->next;
		delete p;                                                 //释放结点空间
		p=adjlist[i].firstedge;
	}
  }
}

/*   
 *前置条件：图已存在
 *输    入：无
 *功    能：输出图中所有顶点及边的数据信息
 *输    出：图中所有顶点及边的数据信息
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::DispALGraph( )                     
{                                  
	int i;
	ArcNode *p;
	cout<<"图的邻接表:\n";
    for(i=0;i<vertexNum;i++){      
		cout<<i<<" "<<adjlist[i].vertex<<" ";	//输出图中顶点的序号i及值
		for(p=adjlist[i].firstedge;p;p=p->next)
			cout<<p->adjvex<<" ";  //输出i号顶点的邻接点的序号 
		cout<<endl;
	}
}

//计算各个顶点的入度
template <class T>
void ALGraph<T>::CountInD()
{
	ArcNode * p;                                             
	int i;
    for(i=0;i<vertexNum;i++)
		adjlist[i].in=0;
	for(i=0;i<vertexNum;i++)
		for (p=adjlist[i].firstedge; p; p=p->next)//依次搜索顶点v的各个邻接点i 
		{
			int v=p->adjvex;
			adjlist[v].in++;        
		}
}
//输出各个顶点的入度
template <class T>
void ALGraph<T>::DispInD()
{
	int i;
	cout<<"In:";
    for(i=0;i<vertexNum;i++)
		cout<<adjlist[i].in<<" ";
	cout<<endl;
}
//topsort
template <class T>
void ALGraph<T>::TopSort()
{
	SeqStack <int> S;
	ArcNode *p;
	int i,count=0;
	cout<<"TopSort:";
    for(i=0;i<vertexNum;i++)
		if(!adjlist[i].in)S.Push(i);
	while(!S.Empty())
	{
		int i=S.Pop();
		count++;
		cout<<adjlist[i].vertex<<" ";
		for(p=adjlist[i].firstedge;p;p=p->next)
		{
			int v=p->adjvex;
			if(!--adjlist[v].in)S.Push(v);
		}
	}
	if (count<vertexNum) throw"Failure";
}

int main()
{
	string a[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N"}; //顶点信息
	int n,e;
	cin>>n>>e;  //输入顶点个数和边个数
    ALGraph<string> G(a,n,e);
	G.DispALGraph();
	G.CountInD();
	G.DispInD();
	try{
		G.TopSort();
	}
	catch(const char *ms)
	{
		cout<<ms<<endl;
	}
    return 0;
}

/*
6 7
0 1 0 3 1 2 1 5 2 4 3 5 4 5
图的邻接表:
0 A 3 1 
1 B 5 2 
2 C 4 
3 D 5 
4 E 5 
5 F 
In:0 1 1 1 1 3 
TopSort:A B C E D F 
*/