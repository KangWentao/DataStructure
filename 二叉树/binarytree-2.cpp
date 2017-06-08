#include<iostream>
#include<string>
using namespace std;

//�������࣬ʵ�ּ���߶ȡ�Ҷ����
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
	int CountLeaf(BiNode<T> *);       //����Ҷ����
	int Depth(BiNode<T> *);	          //����߶�
private:
    BiNode<T> *root;         //ָ�������ͷָ��      
	void Creat(BiNode<T> *&root);//�����캯�����ã��ݹ鷽ʽ����һ�Ŷ�����
    void Release(BiNode<T> *&root);   //�������������� 	
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