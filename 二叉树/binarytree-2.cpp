#include<iostream>
#include<string>
using namespace std;

//二叉树类，实现计算高度、叶子数
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
	BiNode<T> *GetRoot()
	{
		return root;
	}
    int CountLeaf()
	{
		return CountLeaf(root);
	}
	int Depth()
	{
		return Depth(root);
	}
	int CountLeaf(BiNode<T> *);       //计算叶子数
	int Depth(BiNode<T> *);	          //计算高度
private:
    BiNode<T> *root;         //指向根结点的头指针      
	void Creat(BiNode<T> *&root);//被构造函数调用，递归方式生成一颗二叉树
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
/*	string ss,s2;
	cin>>ss;
	s2=ss+"skf";
	cout<<ss<<endl<<s2;
//	getline(cin,ss);
 //   s2=ss;
*/
	cout<<bt.CountLeaf()<<" "<<bt.Depth()<<endl;
    cout<<bt.CountLeaf(bt.GetRoot())<<" "<<bt.Depth(bt.GetRoot())<<endl;
	return 0;
}

/*
Li Sun # Zhao Zhou # # Wang # # Qian # #
3 4 
3 4 
*/
/*
a b # c e # # f # # d # #
3 4 
3 4 
*/