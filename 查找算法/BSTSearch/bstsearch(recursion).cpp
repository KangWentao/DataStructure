#include <iostream>
using namespace std;
//BiNode
template <class T>
struct BiNode
{
	T data;
	BiNode *lchild, *rchild;
};

//BiSortTree
template <class T>
class BiSortTree   
{
public:
	BiSortTree(T r[],int n);    //建立关键字序列r[0]~r[n-1]的二叉排序树
	~BiSortTree( );       //析构函数，释放二叉排序树中所有结点，同二叉链表的析构函数
    void InsertBST(BiNode<T>*&root,BiNode<T> *s);    //插入结点*s
	BiNode<T>* SearchBST(BiNode<T> *root,T k);   //查找值为k的结点，返回值为k所在结点的地址
	void InOrderBST(BiNode<T> *root);   //中序遍历二叉树（递归）
    BiNode<T> *GetRoot()  //获取root值
	{
		return root;
	}
private:
    BiNode<T> *root;    //二叉排序树（即二叉链表）的根指针
    void Release(BiNode<T> *&root);   //析构函数调用
};

//构造函数，将r[0]~r[n-1]各个元素依次插入，生成一棵二叉排序树
template <class T>
BiSortTree<T>::BiSortTree(T r[],int n)//构造函数
{
	root=NULL;  //初始化空二叉树
	int i;
	for(i=0;i<n;i++){   //进行n次插入
		BiNode<T> *s;
		s=new BiNode<T>;
		s->data=r[i];
		s->lchild=s->rchild=NULL;
		InsertBST(root,s);//将结点s插入到二叉排序树中
	}
}

//Insert
template <class T>
void BiSortTree<T>::InsertBST(BiNode<T> *&root,BiNode<T> *s)
{
	if(!root) root=s;
	else
		if(s->data==root->data) return;
		else 
			if(s->data<root->data) InsertBST(root->lchild,s);
			else InsertBST(root->rchild,s);	
}

//中序遍历叉排序树,通过中序遍历是否为递增序列来验证构造的二叉排序树是否正确
template <class T>
void BiSortTree<T>::InOrderBST(BiNode<T> *root){
	if (root){
		InOrderBST(root->lchild);
		cout<<root->data<<" ";
		InOrderBST(root->rchild);
	}
}

//析构函数，调用Release释放内存
template <class T>
BiSortTree<T>::~BiSortTree( )
{ 
    Release(root);	
}

//释放二叉排序树的存储空间，调用析构函数实现
template <class T>
void BiSortTree<T>::Release(BiNode<T>* &root)
{
	if (root){                  
		Release(root->lchild);   //释放左子树
		Release(root->rchild);   //释放右子树
		delete root;
	}  
}

//二叉排序树递归查找算法
template <class T>
BiNode<T>* BiSortTree<T>::SearchBST(BiNode<T> *root, T k)
{
    if(root==NULL)
		return NULL;
    else 
		if (root->data==k) //查找成功，返回		
			return root;
		else
			if (k < root->data)				
				return SearchBST(root->lchild, k);  //查找左子树
			else
				return SearchBST(root->rchild, k);  //查找右子树
}

//二叉排序树的主函数，文件名为bisorttreemain.cpp
int main( ){
    int a[10],n;
	n=0;
	while(1)
	{
		cin>>a[n];
		if(!a[n])break;  //输入数据以0结束
		n++;
	} 
	BiSortTree<int> bst(a,n);//构造二叉排序树
    BiNode<int> *root;
	root=bst.GetRoot();
	cout<<"Inorder:";
	bst.InOrderBST(root);//中序遍历二叉排序树（得到递增有序序列）
	cout<<endl;
	int x;
	cin>>x;
	BiNode<int> *s;
    s=bst.SearchBST(root,x);
	if(!s) cout<<"Failure";
	else cout<<"Success";
	cout<<endl;
	return 0;
} 

/*
3 42 4 32 42 42 32 56 37 0 32
Inorder:3 4 32 37 42 56 
Success
*/