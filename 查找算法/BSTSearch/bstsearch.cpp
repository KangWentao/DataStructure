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
    void InsertBST(BiNode<T> *s);    //������*s
	BiNode<T>* SearchBST(T k);   //����ֵΪk�Ľ�㣬����ֵΪk���ڽ��ĵ�ַ
	void InOrderBST()   //�������
	{
		InOrderBST(root);  //����˽������ݹ麯��
	}
private:
    BiNode<T> *root;    //�����������������������ĸ�ָ��
    void Release(BiNode<T> *&root);   //������������
	void InOrderBST(BiNode<T> *root); 
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
		InsertBST(s);//�����s���뵽������������
	}
}

//Insert BiNode *s
template <class T>
void BiSortTree<T>::InsertBST(BiNode<T> *s)
{
	BiNode<T> *p,*f;
	if(!root) root=s;
	else
	{
		p=root;
		while(p){
			f=p;
			if(s->data==p->data) break;
			else 
				if(s->data<p->data) p=p->lchild;
				else p=p->rchild;
		}
		if (!p)
			if(s->data<f->data) f->lchild=s;
			else f->rchild=s;
	}
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

//�����������ǵݹ����
template <class T>
BiNode<T>* BiSortTree<T>::SearchBST(T k)
{
	BiNode<T> *p=root;
	while (p!=NULL )
	{
		if (p->data==k )return p;		
		else 
			if (k<p->data)p=p->lchild;
			else p=p->rchild;
	}
	return NULL;
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
    cout<<"Inorder:";
	bst.InOrderBST();//��������������������õ������������У�
	cout<<endl;
	int x;
	cin>>x;
	BiNode<int> *s;
    s=bst.SearchBST(x);
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