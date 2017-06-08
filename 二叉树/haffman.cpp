#include<iostream>
using namespace std;

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
	return top==-1;
} 

//��    �ܣ��ж�ջ�Ƿ�Ϊ��
template <class T> 
bool SeqStack<T>::Full( )
{
	return top==StackSize-1;
} 

//huffman tree class
template <class T>
struct BiNode   //�������Ľ��ṹ
{
  T data;       
  BiNode<T> *lchild, *rchild;
};
//ʵ�ֶ������ķǵݹ����
template <class T>
class BiTree{
public:               
	BiTree(); //���캯������ʼ��һ�ö���������ǰ�������ɼ�������
    ~BiTree();         //�����������ͷŶ��������и����Ĵ洢�ռ�
    void PreOrder();     //ǰ�����������
    void LevelOrder();   //��α���������
 //   void InOrder();      //�������������
  //  void PostOrder();    //�������������
private:
    BiNode<T> *root;         //ָ�������ͷָ��      
	void Creat(BiNode<T> *&root);//���вι��캯�����ã��Ա�����һ�Ŷ�����
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
//�ǵݹ�ʵ��ǰ�����������
template <class T>
void BiTree<T>::PreOrder() {
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

//��    �ܣ��������������
template <class T>
void BiTree<T>::LevelOrder()
{
	CirQueue <BiNode<T> *> Q; //����˳����У����ٶ����ᷢ������
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