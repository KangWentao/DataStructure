//graphmain.cpp
#include <iostream>
#include <string>
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
	if(top==-1) return 1;
	else return 0;
} 

//��    �ܣ��ж�ջ�Ƿ�Ϊ��
template <class T> 
bool SeqStack<T>::Full( )
{
	return top==StackSize-1;
} 
//ͼ
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
	int in;     //����������
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
   void CountInD();     //���������������,�洢��adjlist[i].in��
   void DispInD();     //�������������
   void TopSort();     //��������
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
void ALGraph<T>::CountInD()
{
	ArcNode * p;                                             
	int i;
    for(i=0;i<vertexNum;i++)
		adjlist[i].in=0;
	for(i=0;i<vertexNum;i++)
		for (p=adjlist[i].firstedge; p; p=p->next)//������������v�ĸ����ڽӵ�i 
		{
			int v=p->adjvex;
			adjlist[v].in++;        
		}
}
//���������������
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
	string a[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N"}; //������Ϣ
	int n,e;
	cin>>n>>e;  //���붥������ͱ߸���
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
ͼ���ڽӱ�:
0 A 3 1 
1 B 5 2 
2 C 4 
3 D 5 
4 E 5 
5 F 
In:0 1 1 1 1 3 
TopSort:A B C E D F 
*/