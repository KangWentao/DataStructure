#include<iostream>
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
	return top==-1;
} 

//功    能：判断栈是否为满
template <class T> 
bool SeqStack<T>::Full( )
{
	return top==StackSize-1;
} 

//huffman tree class
template <class T>
struct BiNode   //二叉树的结点结构
{
  T data;       
  BiNode<T> *lchild, *rchild;
};
//实现二叉树的非递归遍历
template <class T>
class BiTree{
public:               
	BiTree(); //构造函数，初始化一棵二叉树，其前序序列由键盘输入
    ~BiTree();         //析构函数，释放二叉链表中各结点的存储空间
    void PreOrder();     //前序遍历二叉树
    void LevelOrder();   //层次遍历二叉树
 //   void InOrder();      //中序遍历二叉树
  //  void PostOrder();    //后序遍历二叉树
private:
    BiNode<T> *root;         //指向根结点的头指针      
	void Creat(BiNode<T> *&root);//被有参构造函数调用，以便生成一颗二叉树
    void Release(BiNode<T> *&root);   //被析构函数调用 
};

//定义类中的成员函数
//构造函数:Creat利用创建二叉树
template<class T>
BiTree<T>::BiTree() 
{
    Creat(root);
}

//功    能：递归方法创建一棵二叉树,由构造函数调用
template <class T>
void BiTree<T>::Creat(BiNode<T> * &root)
{
	T ch;	
	cin>>ch;
    if (ch=="#") root = NULL;  //创建结点值为字符串的二叉树
    else{ 
	     root = new BiNode<T>;   //生成一个结点
         root->data=ch;
         Creat(root->lchild);    //递归建立左子树
         Creat(root->rchild);    //递归建立右子树
    } 
}
//功    能：析构函数，释放二叉链表中各结点的存储空间
template<class T> 
BiTree<T>::~BiTree() //析构函数不能带参数
{
	Release(root);
}

//功    能：释放二叉树的存储空间，析构函数调用
template<class T>
void BiTree<T>::Release(BiNode<T>*&root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //释放左子树
      Release(root->rchild);   //释放右子树
      delete root;
  }  
}
//非递归实现前序遍历二叉树
template <class T>
void BiTree<T>::PreOrder() {
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

//功    能：层序遍历二叉树
template <class T>
void BiTree<T>::LevelOrder()
{
	CirQueue <BiNode<T> *> Q; //采用顺序队列，并假定不会发生上溢
    BiNode<T>* x;
    if (root) 
	{
		Q.EnQueue(root);
		while (!Q.Empty()){
			x=Q.DeQueue();
        	cout<<x->data<<" ";			
    		if (x->lchild)    Q.EnQueue(x->lchild);		
			if (x->rchild)    Q.EnQueue(x->rchild);
		}
	}
}

int main()
{
	BiTree<string> bt;
	bt.PreOrder();
	cout<<endl;
	bt.LevelOrder();
	cout<<endl;
	return 0;
}
/*
Li Sun # Zhao Zhou # # Wang # # Qian # #
Li Sun Zhao Zhou Wang Qian 
Li Sun Qian Zhao Zhou Wang 
*/
/*
a b # c e # # f # # d # #
a b c e f d 
a b d c e f 
*/