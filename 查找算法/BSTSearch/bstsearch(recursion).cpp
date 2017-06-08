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
	BiSortTree(T r[],int n);    //�����ؼ�������r[0]~r[n-1]�Ķ���������
	~BiSortTree( );       //�����������ͷŶ��������������н�㣬ͬ�����������������
    void InsertBST(BiNode<T>*&root,BiNode<T> *s);    //������*s
	BiNode<T>* SearchBST(BiNode<T> *root,T k);   //����ֵΪk�Ľ�㣬����ֵΪk���ڽ��ĵ�ַ
	void InOrderBST(BiNode<T> *root);   //����������������ݹ飩
    BiNode<T> *GetRoot()  //��ȡrootֵ
	{
		return root;
	}
private:
    BiNode<T> *root;    //�����������������������ĸ�ָ��
    void Release(BiNode<T> *&root);   //������������
};

//���캯������r[0]~r[n-1]����Ԫ�����β��룬����һ�ö���������
template <class T>
BiSortTree<T>::BiSortTree(T r[],int n)//���캯��
{
	root=NULL;  //��ʼ���ն�����
	int i;
	for(i=0;i<n;i++){   //����n�β���
		BiNode<T> *s;
		s=new BiNode<T>;
		s->data=r[i];
		s->lchild=s->rchild=NULL;
		InsertBST(root,s);//�����s���뵽������������
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

//���������������,ͨ����������Ƿ�Ϊ������������֤����Ķ����������Ƿ���ȷ
template <class T>
void BiSortTree<T>::InOrderBST(BiNode<T> *root){
	if (root){
		InOrderBST(root->lchild);
		cout<<root->data<<" ";
		InOrderBST(root->rchild);
	}
}

//��������������Release�ͷ��ڴ�
template <class T>
BiSortTree<T>::~BiSortTree( )
{ 
    Release(root);	
}

//�ͷŶ����������Ĵ洢�ռ䣬������������ʵ��
template <class T>
void BiSortTree<T>::Release(BiNode<T>* &root)
{
	if (root){                  
		Release(root->lchild);   //�ͷ�������
		Release(root->rchild);   //�ͷ�������
		delete root;
	}  
}

//�����������ݹ�����㷨
template <class T>
BiNode<T>* BiSortTree<T>::SearchBST(BiNode<T> *root, T k)
{
    if(root==NULL)
		return NULL;
    else 
		if (root->data==k) //���ҳɹ�������		
			return root;
		else
			if (k < root->data)				
				return SearchBST(root->lchild, k);  //����������
			else
				return SearchBST(root->rchild, k);  //����������
}

//���������������������ļ���Ϊbisorttreemain.cpp
int main( ){
    int a[10],n;
	n=0;
	while(1)
	{
		cin>>a[n];
		if(!a[n])break;  //����������0����
		n++;
	} 
	BiSortTree<int> bst(a,n);//�������������
    BiNode<int> *root;
	root=bst.GetRoot();
	cout<<"Inorder:";
	bst.InOrderBST(root);//��������������������õ������������У�
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