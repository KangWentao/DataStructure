#include <iostream>
#include <climits>   //INT_MAX
#include <string>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;  
};

template <class T>
class LinkStack
{
public:
    LinkStack( );              //���캯�����ÿ���ջ
    ~LinkStack( );             //�����������ͷ���ջ�и����Ĵ洢�ռ�
    void Push(T x);           //��Ԫ��x��ջ
    T Pop( );                  //��ջ��Ԫ�س�ջ
    T GetTop( );               //ȡջ��Ԫ�أ�����ɾ����
    bool Empty( );             //�ж���ջ�Ƿ�Ϊ��ջ
    void VisitStack();         //����ջ���Ӷ����ף�
private:
    Node<T> *top;             //ջ��ָ�뼴��ջ��ͷָ��
};

/*
 * ǰ��������ջ������
 * ��    �룺��
 * ��    �ܣ�ջ�ĳ�ʼ��
 * ��    ������
 * ��������������һ����ջ
 */

template <class T>
LinkStack<T>::LinkStack( )
{
	top=NULL; 
}
/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ�����ջ
 * ��    ������
 * �����������ͷ�ջ��ռ�õĴ洢�ռ�
 */
template <class T>
LinkStack<T>::~LinkStack( )
{
	while (top)
	{
		Node<T> *p;
		p=top->next;
        delete top;
        top=p;
	}
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺�ڵ�s
 * ��    �ܣ���ջ������ýڵ�
 * ��    ������
 * �����������������ɹ���ջ��������һ��Ԫ��
 */

template<class T> 
void LinkStack<T>::Push(T x)
{
    Node<T> *s;
	s=new Node<T>;  
	if(!s) throw"Overflow";
    s->data = x;     //����һ��������Ϊx�Ľ��s
    s->next = top; 
	top=s;           //�����s����ջ��
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ�ɾ��ջ��Ԫ��
 * ��    �������ɾ���ɹ������ر�ɾԪ��ֵ�������׳��쳣
 * �������������ɾ���ɹ���ջ��������һ��Ԫ��
 */    

template <class T> T LinkStack<T>::Pop( )
{   
    Node<T> *p;
	int x; 
    if (top==NULL) throw "Downflow";
    x=top->data;            //�ݴ�ջ��Ԫ��
    p=top; 
	top=top->next;         //��ջ�����ժ��
    delete p;
    return x;
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ���ȡ��ǰ��ջ��Ԫ��
 * ��    ������ջ���գ����ص�ǰ��ջ��Ԫ��ֵ
 * ����������ջ����
 */

template <class T> 
T LinkStack<T>::GetTop( )
{
    if (top) 
		return top->data;
	else throw"Downflow";
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ��ж�ջ�Ƿ�Ϊ��
 * ��    �������ջΪ�գ�����1�����򣬷���0
 * ����������ջ����
 */

template <class T> 
bool LinkStack<T>::Empty( )
{
    return top==NULL; 
}
template <class T>
void  LinkStack<T>::VisitStack()
{
       Node<T> *p;;
       for(p=top;p;p=p->next)
           cout<<p->data;
}

//huffmantree.h
const int MaxSize=100; 
struct HuffNode{
	int weight;   //Ȩֵ
	string word;  //Ȩֵ��Ӧ����Ϣ
	int parent;   //˫�����������±�
	int lchild,rchild;  //���Һ������������±�
};
class HuffTree
{
private:
	HuffNode hufftree[MaxSize+1];   //huffman���Ĵ洢��1~2*n-1�±꣩
	int n;  //Ȩֵ����
public:
    HuffTree(int w[],string str[],int n);   //initialize
	void SelectMinW(int n,int &min); //ѡ����СȨֵ�ĸ���������±�
	void VisitHuffTree();    //���huffmantree
    int HuffCode(LinkStack<char> S[]);  //���haffman���벢����wplֵ��ջS[1]~S[n]�洢����Ȩֵ�ı���
    void DisplayAllCoding(LinkStack<char> S[]); //�������Ȩֵ��huffman����
};
HuffTree::HuffTree(int w[],string str[],int n){
	int i,min1,min2;
	hufftree[0].weight=INT_MAX;
//	hufftree[0].parent=-1;
	for(i=1;i<=n;i++){
		hufftree[i].weight=w[i];
		hufftree[i].word=str[i];
//		cout<<hufftree[i].word<<" ";
		hufftree[i].parent=-1;
		hufftree[i].lchild=-1;
		hufftree[i].rchild=-1;
	}
	for( ;i<=2*n-1;i++){
		SelectMinW(i,min1);
		SelectMinW(i,min2);
//		cout<<"select: "<<min1<<"\t"<<min2<<endl;
		hufftree[i].lchild=min1;
		hufftree[i].rchild=min2;
		hufftree[i].weight=hufftree[min1].weight+hufftree[min2].weight;
		hufftree[i].parent=-1;
		hufftree[min1].parent=i;
		hufftree[min2].parent=i;
	}
	this->n=n;
}

void HuffTree::SelectMinW(int n,int &min){
	min=0;
	for(int i=1;i<=n;i++)
		if(hufftree[i].parent==-1&&
		    hufftree[i].weight<hufftree[min].weight) min=i;
	hufftree[min].parent=0;//������һ���ظ���ѡ
}

void HuffTree::VisitHuffTree(){
	cout<<"No\tweight\tparent\tlchild\trchild\n";
	for(int i=1;i<=2*n-1;i++){
		cout<<i<<"\t"<<hufftree[i].weight<<"\t";
		cout<<hufftree[i].parent<<"\t";
		cout<<hufftree[i].lchild<<"\t"<<hufftree[i].rchild<<"\n";
	}
}
	
int HuffTree::HuffCode(LinkStack<char> S[]){

	int i,pos,wpl=0,len;
	for(i=1;i<=n;i++){
		pos=i;
		len=0;
		while(hufftree[pos].parent!=-1){
			int p=hufftree[pos].parent;
			if(hufftree[p].lchild==pos) S[i].Push('0');
			else S[i].Push('1');
			len++;
			pos=p;
		}
		wpl+=hufftree[i].weight*len;
	}
	return wpl;
}
void HuffTree::DisplayAllCoding(LinkStack<char> S[]){
	int wpl=0,len;
	for(int i=1;i<=n;i++){
		len=0;
		cout<<"Coding of "<<hufftree[i].weight<<"("<<hufftree[i].word<<"):";
//	    S[i].VisitStack();   //ջδ��
		while(!S[i].Empty())
		{
			cout<<S[i].Pop();
			len++;
		}
		cout<<endl;
	}	
}

int main(){
	int w[MaxSize/2],n;//w�洢Ȩֵ��n�洢Ȩֵ����//={INT_MAX,5,29,7,8,14,23,3,11},n=8;
    string inf[MaxSize];//�洢����Ȩֵ��Ӧ����Ϣ(һ������)//={" ","��","��","��","��","��","��","��","��"};
    cin>>n;   //����Ȩֵ����
	int i;
	for(i=1;i<=n;i++)
		cin>>w[i];   //����Ȩֵ
	for(i=1;i<=n;i++)
		cin>>inf[i];  //�������Ȩֵ��Ӧ�ĺ���
	
	HuffTree ht(w,inf,n);   //create huffman tree
//	ht.VisitHuffTree();     //display huffman tree

	LinkStack<char> S[100];   //storage huffman coding
	int wpl=ht.HuffCode(S);   //calculate the huffman coding for every weight and wpl
	ht.DisplayAllCoding(S);   //display huffman coding
	cout<<"WPL="<<wpl<<endl;  //display wpl
	return 0;
}
/*

5
12 35 17 7 22
�� �� Ǯ �� ��
No      weight  parent  lchild  rchild
1       12      6       -1      -1
2       35      8       -1      -1
3       17      7       -1      -1
4       7       6       -1      -1
5       22      8       -1      -1
6       19      7       4       1
7       36      9       3       6
8       57      9       5       2
9       93      -1      7       8
Coding of 12(��):011
Coding of 35(��):11
Coding of 17(Ǯ):00
Coding of 7(��):010
Coding of 22(��):10
WPL=205
*/