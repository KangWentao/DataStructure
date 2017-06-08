//graphmain.cpp
#include <iostream>
#include <string>
using namespace std;

const int MaxSize=20;     // ������������ֵ
int visited[MaxSize];     //���ʱ�־���飨0��ʾδ���ʣ�1��ʾ�ѷ��ʣ�

//����߱���
struct ArcNode                 
{
	int adjvex;                    //�ڽӵ�����
	ArcNode *next;                 //ָ����һ���߽���ָ��
};

 //���嶥�����
template <class T>
struct VertexNode              
{
	T vertex;                 //���������
	ArcNode *firstedge;        //ָ���һ���߱����ͷָ��
};

//�ڽӱ���
template <class T>
class ALGraph
{
public:
   ALGraph(T a[ ], int n, int e);   //���캯������ʼ��һ����n������e���ߵ�ͼ
   ~ALGraph();                      //�����������ͷ��ڽӱ��и��߱���Ĵ洢�ռ�
   void DispALGraph();              //����ڽӱ�
   void CountInD(int ind[]);     //���������������,�洢��ind��
   void CountOutD(int outd[]);   //�����������ĳ���,�洢��outd��
private:
   VertexNode<T> adjlist[MaxSize];  //��Ŷ���������
   int vertexNum, arcNum;           //ͼ�Ķ������ͱ���
};

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

	for (int k=0; k<arcNum; k++)    //��������ÿһ���ߣ�������Ӧ�߱��в�����
    { 
		cin>>i>>j;                         //�������������������������
        ArcNode *s=new ArcNode; 
		s->adjvex=j;  //����һ���߱���s
	    s->next=adjlist[i].firstedge;      //�����s���뵽i�ű��ͷ���֮��  
        adjlist[i].firstedge=s;
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
 *��    ����ͼ�����ж��㼰�ߵ�������Ϣ
 *����������ͼ���ֲ���
 */
template <class T>
void ALGraph<T>::DispALGraph( )                     
{                                  
	int i;
	ArcNode *p;
	cout<<"ͼ���ڽӱ�:\n";
    for(i=0;i<vertexNum;i++){      
		cout<<i<<" "<<adjlist[i].vertex<<" ";	//���ͼ�ж�������i��ֵ
		for(p=adjlist[i].firstedge;p;p=p->next)
			cout<<p->adjvex<<" ";  //���i�Ŷ�����ڽӵ����� 
		cout<<endl;
	}
}

//���������������
template <class T>
void ALGraph<T>::CountInD(int ind[])
{
	ArcNode * p;                                             
	int i;
    for(i=0;i<vertexNum;i++)
		ind[i]=0;
	for(i=0;i<vertexNum;i++)
		for (p=adjlist[i].firstedge; p; p=p->next)//������������v�ĸ����ڽӵ�i 
		{
			int v=p->adjvex;
			ind[v]++;        
		}
}
//�����������ĳ���
template <class T>
void ALGraph<T>::CountOutD(int outd[])
{
	ArcNode * p;                                             
	int i;
    for(i=0;i<vertexNum;i++)
		outd[i]=0;
	for(i=0;i<vertexNum;i++)
		for (p=adjlist[i].firstedge; p; p=p->next)//������������v�ĸ����ڽӵ�i 
		{
			outd[i]++;        
		}
}
int main()
{
	string a[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N"}; //������Ϣ
	int i,n,e;
	cin>>n>>e;  //���붥������ͱ߸���
    ALGraph<string> G(a,n,e);
	G.DispALGraph();
	int ind[MaxSize];
	cout<<"Indegree:";
	G.CountInD(ind);	
    for(i=0;i<n;i++)
		cout<<ind[i]<<" ";// ���������������
	cout<<endl;
    int outd[MaxSize];
	cout<<"OutDegree:";
	G.CountOutD(outd);
    for(i=0;i<n;i++)
		cout<<outd[i]<<" "; // �����������ĳ���
	return 0;
}

/*
6 7
0 1 0 3 1 2 1 5 2 4 3 5 4 5
ͼ���ڽӱ�:
0 A 3 1 
1 B 5 2 
2 C 4 
3 D 5 
4 E 5 
5 F 
Indegree:0 1 1 1 1 3 
OutDegree:2 2 1 1 1 0 
 Press any key to continue
*/