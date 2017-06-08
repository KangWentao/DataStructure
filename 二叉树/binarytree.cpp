#include<iostream>
#include<string>
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
private:
    T data[QueueSize];           //存放队列元素的数组
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
bool SeqStack<T>::Empty( )
{
	return top==StackSize-1;
} 


template <class T>
struct BiNode   //二叉树的结点结构
{
  T data;       
  BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree{
public:               
	BiTree(BiNode <T> *&root); //构造函数，初始化一棵二叉树，其前序序列由键盘输入
    ~BiTree();         //析构函数，释放二叉链表中各结点的存储空间

    void PreOrder(BiNode<T> *root);     //前序遍历二叉树
    void InOrder(BiNode<T> *root);      //中序遍历二叉树
    void PostOrder(BiNode<T> *root);    //后序遍历二叉树
    void LeverOrder(BiNode<T> *root);   //层序遍历二叉树

private:
    BiNode<T> *root;         //指向根结点的头指针      
	void Creat(BiNode<T> *&root);//被有参构造函数调用，以便生成一颗二叉树
    void Release(BiNode<T> *root);   //被析构函数调用 
};

//定义类中的成员函数，文件名为bitree.cpp


/*
 *前置条件：二叉树不存在
 *输    入：无
 *功    能：构造一棵二叉树
 *输    出：无
 *后置条件：产生一棵二叉树 
 */
template<class T>
BiTree<T>::BiTree( BiNode<T> *&root) //构造函数
{
    cout<<"请输入创建一棵二叉树的结点数据"<<endl;
	Creat(root);
    this->root=root;  //将生成的二叉树的根指针送给类的私有变量root，以便析构函数使用
}

/*
 *前置条件：空二叉树
 *输    入：数据ch;
 *功    能：初始化一棵二叉树,由构造函数调用
 *输    出：无
 *后置条件：生成一棵二叉树
 */

template <class T>
void BiTree<T>::Creat(BiNode<T> * &root)
{
	T ch;	
	cin>>ch;
    if (ch=="#") root = NULL;
    else{ 
	     root = new BiNode<T>;   //生成一个结点
         root->data=ch;
         Creat(root->lchild);    //递归建立左子树
         Creat(root->rchild);    //递归建立右子树
    } 
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：释放二叉链表中各结点的存储空间
 *输    出：无
 *后置条件：二叉树不存在 
 */
template<class T> //destructors must have a 'void' formal parameter list
BiTree<T>::~BiTree()   //析构函数不能带参数
{
	Release(root);
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：前序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */

template <class T>//非递归实现前序遍历二叉树
void BiTree<T>::PreOrder(BiNode<T> *root) {
     SeqStack <BiNode<T> *> S; //栈初始化 
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
//前序遍历二叉树的递归算法
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
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：中序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */
template <class T>
void BiTree<T>::InOrder (BiNode<T> *root)
{
    if (root==NULL)  return;      //递归调用的结束条件	          
    else{	
        InOrder(root->lchild);    //中序递归遍历root的左子树
        cout<<root->data<<" ";    //访问根结点的数据域
        InOrder(root->rchild);    //中序递归遍历root的右子树
	}
}
/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：后序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变 
 */
template <class T>
void BiTree<T>::PostOrder(BiNode<T> *root)
{ 
    if (root==NULL)   return;       //递归调用的结束条件
    else{	
        PostOrder(root->lchild);    //后序递归遍历root的左子树
        PostOrder(root->rchild);    //后序递归遍历root的右子树
        cout<<root->data<<" ";      //访问根结点的数据域
	}
}

/*
 *前置条件：二叉树已存在
 *输    入：无
 *功    能：层序遍历二叉树
 *输    出：二叉树中结点的一个线性排列
 *后置条件：二叉树不变
 */
template <class T>
void BiTree<T>::LeverOrder(BiNode<T> *root)
{
	CirQueue <BiNode<T> *> Q; //采用顺序队列，并假定不会发生上溢
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
 *前置条件：二叉树已经存在
 *输    入：无
 *功    能：释放二叉树的存储空间，析构函数调用
 *输    出：无
 *后置条件：二叉树不存在
 */
template<class T>
void BiTree<T>::Release(BiNode<T>* root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //释放左子树
      Release(root->rchild);   //释放右子树
      delete root;
  }  
}


//求二叉树叶子个数
template<class T>
int CountLeaf(BiNode<T> *root)  //普通函数
{
	if(root==NULL)  
		return 0;
	else
		if (!root->lchild&&!root->rchild)
			return 1;
		else 
			return CountLeaf(root->lchild)+CountLeaf(root->rchild);

}

//求结点总数
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