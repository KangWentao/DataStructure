//graphmain.cpp
#include <iostream>
#include <string>
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
   int Count( );                    //������ͨ��������������ֵΪ��ͨ�����ĸ���
   void DFSTraverse(int v);         //������ȱ���ͼ
   void BFSTraverse(int v);          //������ȱ���ͼ
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
        s=new ArcNode; 
		s->adjvex=i;  //����һ���߱���s
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

template <class T>
int ALGraph<T>::Count( )                     
{                                  
	int i,n=0;

	for(i=0;i<vertexNum;i++) visited[i]=0;
	for(i=0;i<vertexNum;i++){       
		if(!visited[i]){
			n++;
			BFSTraverse(i);
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
	ArcNode * p;                                             
	int i;
	cout<<adjlist[v].vertex<<" ";  
	visited[v]=1;
    for (p=adjlist[v].firstedge; p; p=p->next)//������������v�ĸ����ڽӵ�i 
    {
		i=p->adjvex;
		if (visited[i]==0) DFSTraverse(i);        
    }
}
/*   
 *ǰ��������ͼ�Ѵ���
 *��    �룺��������ʼ����v
 *��    �ܣ��Ӷ���v����������ȱ���ͼ
 *��    ����ͼ�ж����һ����������
 *����������ͼ���ֲ���
 */
template <class T>
void ALGraph<T>::BFSTraverse(int v)//��v������������ȱ���ͼ��һ����ͨ��ͼ��
{
	CirQueue<int> Q;
	ArcNode * p;    
	int i;
	cout<<adjlist[v].vertex<<" ";
	visited[v]=1;
	Q.EnQueue(v);
	while(!Q.Empty())
	{
		v=Q.DeQueue();
	    for (p=adjlist[v].firstedge; p; p=p->next)//������������v�ĸ����ڽӵ�i 
		{
			i=p->adjvex;
			if(visited[i]==0)
			{
				cout<<adjlist[i].vertex<<" ";
				visited[i]=1;
				Q.EnQueue(i);
			}
		}
	} 
}
int main()
{
	string a[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N"}; //������Ϣ
	int i,n,e;
	cin>>n>>e;  //���붥������ͱ߸���
    ALGraph<string> G(a,n,e);
	G.DispALGraph();
	for(i=0;i<n;i++)
		visited[i]=0;
	cout<<"DFS:";
	G.DFSTraverse(0);
	cout<<endl;
    for(i=0;i<n;i++)
		visited[i]=0;
	cout<<"BFS:";
	G.BFSTraverse(0);

    cout<<"\n��ͨ��������:";
	cout<<G.Count()<<endl;
	return 0;
}

/*
void main()
{	
	
    cout<<"����ͼ���ڽӱ�\n";
    string a[] = {"A","B","C","D","E","F","G","H","I"};//������Ϣ
    ALGraph<string> G( a, 9, 8);  //����ͼ��9�����㣬8����
	G.PrintInf();
	cout<<"��ͨ����������"<<G.Count()<<endl;
}*/
/*
6 7
0 1 0 3 1 2 1 5 2 4 3 5 4 5
ͼ���ڽӱ�:
0 A 3 1 
1 B 5 2 0 
2 C 4 1 
3 D 5 0 
4 E 5 2 
5 F 4 3 1 
DFS:A D F E C B 
BFS:A D B F C E 
6 5
0 1 0 3 1 5 2 4 3 5
*/