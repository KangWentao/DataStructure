#include<iostream>
#include<string>
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
bool SeqStack<T>::Empty( )
{
	return top==StackSize-1;
} 


template <class T>
struct BiNode   //�������Ľ��ṹ
{
  T data;       
  BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree{
public:               
	BiTree(BiNode <T> *&root); //���캯������ʼ��һ�ö���������ǰ�������ɼ�������
    ~BiTree();         //�����������ͷŶ��������и����Ĵ洢�ռ�

    void PreOrder(BiNode<T> *root);     //ǰ�����������
    void InOrder(BiNode<T> *root);      //�������������
    void PostOrder(BiNode<T> *root);    //�������������
    void LeverOrder(BiNode<T> *root);   //�������������

private:
    BiNode<T> *root;         //ָ�������ͷָ��      
	void Creat(BiNode<T> *&root);//���вι��캯�����ã��Ա�����һ�Ŷ�����
    void Release(BiNode<T> *root);   //�������������� 
};

//�������еĳ�Ա�������ļ���Ϊbitree.cpp


/*
 *ǰ��������������������
 *��    �룺��
 *��    �ܣ�����һ�ö�����
 *��    ������
 *��������������һ�ö����� 
 */
template<class T>
BiTree<T>::BiTree( BiNode<T> *&root) //���캯��
{
    cout<<"�����봴��һ�ö������Ľ������"<<endl;
	Creat(root);
    this->root=root;  //�����ɵĶ������ĸ�ָ���͸����˽�б���root���Ա���������ʹ��
}

/*
 *ǰ���������ն�����
 *��    �룺����ch;
 *��    �ܣ���ʼ��һ�ö�����,�ɹ��캯������
 *��    ������
 *��������������һ�ö�����
 */

template <class T>
void BiTree<T>::Creat(BiNode<T> * &root)
{
	T ch;	
	cin>>ch;
    if (ch=="#") root = NULL;
    else{ 
	     root = new BiNode<T>;   //����һ�����
         root->data=ch;
         Creat(root->lchild);    //�ݹ齨��������
         Creat(root->rchild);    //�ݹ齨��������
    } 
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��ͷŶ��������и����Ĵ洢�ռ�
 *��    ������
 *���������������������� 
 */
template<class T> //destructors must have a 'void' formal parameter list
BiTree<T>::~BiTree()   //�����������ܴ�����
{
	Release(root);
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ�ǰ�����������
 *��    �����������н���һ����������
 *�������������������� 
 */

template <class T>//�ǵݹ�ʵ��ǰ�����������
void BiTree<T>::PreOrder(BiNode<T> *root) {
     SeqStack <BiNode<T> *> S; //ջ��ʼ�� 
	 BiNode <T> *x;
     if(root) S.Push(root);
     while (!S.Empty( )) {
         x=S.Pop( );
         cout<<x->data<<" ";
         if (x->rchild!= NULL)  
			 S.Push(x->rchild);
         if (x->lchild!= NULL)  
			 S.Push(x->lchild);
     }
}


/*
//ǰ������������ĵݹ��㷨
template<class T>
void BiTree<T>::PreOrder(BiNode<T> *root)
{
	if(root==NULL)  return;
	else{		
		cout<<root->data<<" ";
        PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
*/

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *�������������������� 
 */
template <class T>
void BiTree<T>::InOrder (BiNode<T> *root)
{
    if (root==NULL)  return;      //�ݹ���õĽ�������	          
    else{	
        InOrder(root->lchild);    //����ݹ����root��������
        cout<<root->data<<" ";    //���ʸ�����������
        InOrder(root->rchild);    //����ݹ����root��������
	}
}
/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *�������������������� 
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{ 
    if (root==NULL)   return;       //�ݹ���õĽ�������
    else{	
        PostOrder(root->lchild);    //����ݹ����root��������
        PostOrder(root->rchild);    //����ݹ����root��������
        cout<<root->data<<" ";      //���ʸ�����������
	}
}

/*
 *ǰ���������������Ѵ���
 *��    �룺��
 *��    �ܣ��������������
 *��    �����������н���һ����������
 *��������������������
 */
template <class T>
void BiTree<T>::LeverOrder(BiNode<T> *root)
{
	CirQueue <BiNode<T> *> Q; //����˳����У����ٶ����ᷢ������
    BiNode<T>* q;
    if (root==NULL) 
		cout<<"The tree is empty\n";
	else{
		Q.EnQueue(root);
		while (!Q.Empty()){
			q=Q.DeQueue();
     		cout<<q->data<<" "; 		
    		if (q->lchild)    Q.EnQueue(q->lchild);		
			if (q->rchild)    Q.EnQueue(q->rchild);
		}
	}
}



/*
 *ǰ���������������Ѿ�����
 *��    �룺��
 *��    �ܣ��ͷŶ������Ĵ洢�ռ䣬������������
 *��    ������
 *����������������������
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //�ͷ�������
      Release(root->rchild);   //�ͷ�������
      delete root;
  }  
}


//�������Ҷ�Ӹ���
template<class T>
int CountLeaf(BiNode<T> *root)  //��ͨ����
{
	if(root==NULL)  
		return 0;
	else
		if (!root->lchild&&!root->rchild)
			return 1;
		else 
			return CountLeaf(root->lchild)+CountLeaf(root->rchild);

}

//��������
template <class T>
int Count(BiNode <T> *root)
{
    if (!root)  return 0;
    else {
           return Count(root->lchild)
                      +Count(root->rchild)+1;
    }
}


int main()
{
	return 0;
}