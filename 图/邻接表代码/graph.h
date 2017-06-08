//graph.h
#ifndef GRAPH_H                  //定义头文件
#define GRAPH_H                
using namespace std;
const int MaxSize=12;  
struct ArcNode                   //定义边表结点
{
  int adjvex;                    //邻接点域
  ArcNode *next;                 //指向下一个边结点的指针
};
template <class T>
struct VertexNode               //定义顶点表结点
{
  T vertex;                     //顶点的名称
  ArcNode *firstedge;           //边表的头指针
};
template <class T>
class ALGraph
{
public:
   ALGraph(T a[ ], int n, int e);   //构造函数，初始化一个有n个顶点e条边的图
   ~ALGraph();                      //析构函数，释放邻接表中各边表结点的存储空间
   void PrintInf();                 //输出邻接表
   int Count( );                    //计算连通分量个数，返回值为连通分量的个数
   void DFSTraverse(int v);         //深度优先遍历图
   
private:
   VertexNode<T> adjlist[MaxSize];  //存放顶点表的数组
   int vertexNum, arcNum;           //图的顶点数和边数
};
#endif


/*
 *前置条件：图不存在
 *输    入：无 
 *功    能：图的初始化
 *输    出：无
 *后置条件：得到一个有向图
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
	cout<<"请输入各边所依附的两个顶点的序号:\n";
	for (int k=0; k<arcNum; k++)           //依次输入每一条边，并在相应边表中插入结点
    { 
		cin>>i>>j;                         //输入边所依附的两个顶点的序号
        ArcNode *s=new ArcNode; s->adjvex=j;  //生成一个边表结点s
	    s->next=adjlist[i].firstedge;      //将结点s插入到i号表的头结点之后  
        adjlist[i].firstedge=s;
        s=new ArcNode; s->adjvex=i;  //生成一个边表结点s
	    s->next=adjlist[j].firstedge;      //将结点s插入到j号表的头结点之后  
        adjlist[j].firstedge=s;
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
 *输    出：图中所有顶点的数据信息
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::PrintInf( )                     
{                                  
	int i;
	ArcNode *p;
	cout<<"输出图的邻接表：\n";
    for(i=0;i<vertexNum;i++){       //输出图中所有的顶点
		cout<<i<<" "<<adjlist[i].vertex<<"   ";	
		for(p=adjlist[i].firstedge;p;p=p->next)
			cout<<p->adjvex<<"   ";
		cout<<endl;
	}
	cout<<endl;
}

template <class T>
int ALGraph<T>::Count( )                     
{                                  
	int i,n=0;

	for(i=0;i<vertexNum;i++) visited[i]=0;
	for(i=0;i<vertexNum;i++){       
		if(!visited[i]){
			n++;
			DFSTraverse(i);
		}
		
	}
	return n;
}

/*   
 *前置条件：图已存在
 *输    入：遍历的起始顶点v
 *功    能：从顶点v出发深度优先遍历图
 *输    出：图中顶点的一个线性排列
 *后置条件：图保持不变
 */
template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
	if ( v>vertexNum) throw "位置";      //顶点输入错误则抛出异常
	ArcNode * p;                                             
	int wj;
	cout<<adjlist[v].vertex<<" ";  
	visited[v]=1;
    p=adjlist[v].firstedge;    
    while (p)                   //依次搜索顶点v的邻接点j
    {
       wj=p->adjvex;
       if (visited[wj]==0) DFSTraverse(wj);
	   p=p->next;           
    }
}
