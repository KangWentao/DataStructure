//graph.h
#ifndef GRAPH_H                  //����ͷ�ļ�
#define GRAPH_H                
using namespace std;
const int MaxSize=12;  
struct ArcNode                   //����߱���
{
  int adjvex;                    //�ڽӵ���
  ArcNode *next;                 //ָ����һ���߽���ָ��
};
template <class T>
struct VertexNode               //���嶥�����
{
  T vertex;                     //���������
  ArcNode *firstedge;           //�߱��ͷָ��
};
template <class T>
class ALGraph
{
public:
   ALGraph(T a[ ], int n, int e);   //���캯������ʼ��һ����n������e���ߵ�ͼ
   ~ALGraph();                      //�����������ͷ��ڽӱ��и��߱���Ĵ洢�ռ�
   void PrintInf();                 //����ڽӱ�
   int Count( );                    //������ͨ��������������ֵΪ��ͨ�����ĸ���
   void DFSTraverse(int v);         //������ȱ���ͼ
   
private:
   VertexNode<T> adjlist[MaxSize];  //��Ŷ���������
   int vertexNum, arcNum;           //ͼ�Ķ������ͱ���
};
#endif


/*
 *ǰ��������ͼ������
 *��    �룺�� 
 *��    �ܣ�ͼ�ĳ�ʼ��
 *��    ������
 *�����������õ�һ������ͼ
 */
template <class T>
ALGraph<T>::ALGraph(T a[ ], int n, int e)
{
    arcNum = e;                             //����
	vertexNum=n;                            //������
    int i,j;
	for (i=0; i<vertexNum; i++)
	{  
       
	   adjlist[i].vertex = a[i];
	   adjlist[i].firstedge = NULL;
	    
	}
	cout<<"�����������������������������:\n";
	for (int k=0; k<arcNum; k++)           //��������ÿһ���ߣ�������Ӧ�߱��в�����
    { 
		cin>>i>>j;                         //�������������������������
        ArcNode *s=new ArcNode; s->adjvex=j;  //����һ���߱���s
	    s->next=adjlist[i].firstedge;      //�����s���뵽i�ű��ͷ���֮��  
        adjlist[i].firstedge=s;
        s=new ArcNode; s->adjvex=i;  //����һ���߱���s
	    s->next=adjlist[j].firstedge;      //�����s���뵽j�ű��ͷ���֮��  
        adjlist[j].firstedge=s;
	}
}
/*   ǰ��������ͼ�Ѵ���
 *   ��    �룺�� 
 *   ��    �ܣ�����ͼ
 *   ��    ������
 *   �����������ͷ�ͼ��ռ�õĴ洢�ռ�
 */
template <class T>
ALGraph<T>::~ALGraph( )
{
  for (int i=0; i<vertexNum; i++)
  {
    ArcNode * p=adjlist[i].firstedge;
	while (p!=NULL)                                              //ѭ��ɾ��
	{
	  adjlist[i].firstedge=p->next;
	  delete p;                                                 //�ͷŽ��ռ�
      p=adjlist[i].firstedge;
	}
  }
}

/*   
 *ǰ��������ͼ�Ѵ���
 *��    �룺��
 *��    �ܣ����ͼ�����ж��㼰�ߵ�������Ϣ
 *��    ����ͼ�����ж����������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
void ALGraph<T>::PrintInf( )                     
{                                  
	int i;
	ArcNode *p;
	cout<<"���ͼ���ڽӱ�\n";
    for(i=0;i<vertexNum;i++){       //���ͼ�����еĶ���
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
 *ǰ��������ͼ�Ѵ���
 *��    �룺��������ʼ����v
 *��    �ܣ��Ӷ���v����������ȱ���ͼ
 *��    ����ͼ�ж����һ����������
 *����������ͼ���ֲ���
 */
template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
	if ( v>vertexNum) throw "λ��";      //��������������׳��쳣
	ArcNode * p;                                             
	int wj;
	cout<<adjlist[v].vertex<<" ";  
	visited[v]=1;
    p=adjlist[v].firstedge;    
    while (p)                   //������������v���ڽӵ�j
    {
       wj=p->adjvex;
       if (visited[wj]==0) DFSTraverse(wj);
	   p=p->next;           
    }
}
