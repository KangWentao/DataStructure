#include<iostream>
#include<cstring>
using namespace std;

//二叉树类，实现二叉树的递归算法：三种遍历，计算高度、叶子数
template <class T>
struct BiNode   //二叉树的结点结构
{
  T data;       
  BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree{
public:               
	BiTree(); //构造函数，初始化一棵二叉树，其前序序列由键盘输入
    ~BiTree();         //析构函数，释放二叉链表中各结点的存储空间
    void PreOrder(void)
	{
		PreOrder(root);
	}
	void InOrder(void)
	{
		InOrder(root);
	}
	void PostOrder(void)
	{
		PostOrder(root);
	}
    int CountLeaf()
	{
		return CountLeaf(root);
	}
	int Depth()
	{
		return Depth(root);
	}
	int Depth(BiNode<T> *);	
	BiNode<T> *GetRoot()
	{
		return root;
	}
private:
    BiNode<T> *root;         //指向根结点的头指针      
	void Creat(BiNode<T> *&root);//被构造函数调用，递归方式生成一颗二叉树
    void Release(BiNode<T> *&root);     //被析构函数调用 
	void PreOrder(BiNode<T> *root);     //前序遍历二叉树
    void InOrder(BiNode<T> *root);      //中序遍历二叉树
    void PostOrder(BiNode<T> *root);    //后序遍历二叉树
    int CountLeaf(BiNode<T> *);
	
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

//前序遍历二叉树
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

//功    能：中序遍历二叉树
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
//功    能：后序遍历二叉树
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

//求二叉树叶子个数
template<class T>
int BiTree<T>::CountLeaf(BiNode<T> *root)  //普通函数
{
	if(root==NULL)  
		return 0;
	else
		if (!root->lchild&&!root->rchild)
			return 1;
		else 
			return CountLeaf(root->lchild)+CountLeaf(root->rchild);

}

//calculate the depth
template <class T>
int BiTree<T>::Depth(BiNode <T> *root)
{
    if (!root)  return 0;
    else {
		int hl=Depth(root->lchild);
		int hr=Depth(root->rchild);
		if(hl>hr) 
			return hl+1;
		else 
			return hr+1;
    }
}

int main()
{
	BiTree<string> bt;
	bt.PreOrder();
	cout<<endl;
	bt.InOrder();
	cout<<endl;
	bt.PostOrder();
	cout<<endl;
 	cout<<bt.CountLeaf()<<" "<<bt.Depth()<<endl;
	cout<<bt.Depth(bt.GetRoot());
	return 0;
}

/*
a # b c # # #
a b c 
a c b 
c b a 
*/