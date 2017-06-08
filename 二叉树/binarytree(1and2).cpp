#include<iostream>
#include<cstring>
using namespace std;

//�������࣬ʵ�ֶ������ĵݹ��㷨�����ֱ���������߶ȡ�Ҷ����
template <class T>
struct BiNode   //�������Ľ��ṹ
{
  T data;       
  BiNode<T> *lchild, *rchild;
};

template <class T>
class BiTree{
public:               
	BiTree(); //���캯������ʼ��һ�ö���������ǰ�������ɼ�������
    ~BiTree();         //�����������ͷŶ��������и����Ĵ洢�ռ�
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
    BiNode<T> *root;         //ָ�������ͷָ��      
	void Creat(BiNode<T> *&root);//�����캯�����ã��ݹ鷽ʽ����һ�Ŷ�����
    void Release(BiNode<T> *&root);     //�������������� 
	void PreOrder(BiNode<T> *root);     //ǰ�����������
    void InOrder(BiNode<T> *root);      //�������������
    void PostOrder(BiNode<T> *root);    //�������������
    int CountLeaf(BiNode<T> *);
	
};

//�������еĳ�Ա����

//���캯��:Creat���ô���������
template<class T>
BiTree<T>::BiTree() 
{
    Creat(root);
}

//��    �ܣ��ݹ鷽������һ�ö�����,�ɹ��캯������
template <class T>
void BiTree<T>::Creat(BiNode<T> * &root)
{
	T ch;	
	cin>>ch;
    if (ch=="#") root = NULL;  //�������ֵΪ�ַ����Ķ�����
    else{ 
	     root = new BiNode<T>;   //����һ�����
         root->data=ch;
         Creat(root->lchild);    //�ݹ齨��������
         Creat(root->rchild);    //�ݹ齨��������
    } 
}
//��    �ܣ������������ͷŶ��������и����Ĵ洢�ռ�
template<class T> 
BiTree<T>::~BiTree() //�����������ܴ�����
{
	Release(root);
}

//��    �ܣ��ͷŶ������Ĵ洢�ռ䣬������������
template<class T>
void BiTree<T>::Release(BiNode<T>*&root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //�ͷ�������
      Release(root->rchild);   //�ͷ�������
      delete root;
  }  
}

//ǰ�����������
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

//��    �ܣ��������������
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
//��    �ܣ��������������
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

//�������Ҷ�Ӹ���
template<class T>
int BiTree<T>::CountLeaf(BiNode<T> *root)  //��ͨ����
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