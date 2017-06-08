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
    LinkStack( );              //构造函数，置空链栈
    ~LinkStack( );             //析构函数，释放链栈中各结点的存储空间
    void Push(T x);           //将元素x入栈
    T Pop( );                  //将栈顶元素出栈
    T GetTop( );               //取栈顶元素（并不删除）
    bool Empty( );             //判断链栈是否为空栈
    void VisitStack();         //遍历栈（从顶到底）
private:
    Node<T> *top;             //栈顶指针即链栈的头指针
};

/*
 * 前置条件：栈不存在
 * 输    入：无
 * 功    能：栈的初始化
 * 输    出：无
 * 后置条件：构造一个空栈
 */

template <class T>
LinkStack<T>::LinkStack( )
{
	top=NULL; 
}
/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：销毁栈
 * 输    出：无
 * 后置条件：释放栈所占用的存储空间
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
 * 前置条件：栈已存在
 * 输    入：节点s
 * 功    能：在栈顶插入该节点
 * 输    出：无
 * 后置条件：如果插入成功，栈顶增加了一个元素
 */

template<class T> 
void LinkStack<T>::Push(T x)
{
    Node<T> *s;
	s=new Node<T>;  
	if(!s) throw"Overflow";
    s->data = x;     //申请一个数据域为x的结点s
    s->next = top; 
	top=s;           //将结点s插在栈顶
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：删除栈顶元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出异常
 * 后置条件：如果删除成功，栈顶减少了一个元素
 */    

template <class T> T LinkStack<T>::Pop( )
{   
    Node<T> *p;
	int x; 
    if (top==NULL) throw "Downflow";
    x=top->data;            //暂存栈顶元素
    p=top; 
	top=top->next;         //将栈顶结点摘链
    delete p;
    return x;
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：读取当前的栈顶元素
 * 输    出：若栈不空，返回当前的栈顶元素值
 * 后置条件：栈不变
 */

template <class T> 
T LinkStack<T>::GetTop( )
{
    if (top) 
		return top->data;
	else throw"Downflow";
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：判断栈是否为空
 * 输    出：如果栈为空，返回1，否则，返回0
 * 后置条件：栈不变
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
	int weight;   //权值
	string word;  //权值对应的信息
	int parent;   //双亲所在数组下标
	int lchild,rchild;  //左右孩子所在数组下标
};
class HuffTree
{
private:
	HuffNode hufftree[MaxSize+1];   //huffman树的存储（1~2*n-1下标）
	int n;  //权值个数
public:
    HuffTree(int w[],string str[],int n);   //initialize
	void SelectMinW(int n,int &min); //选择最小权值的根结点所在下标
	void VisitHuffTree();    //输出huffmantree
    int HuffCode(LinkStack<char> S[]);  //设计haffman编码并计算wpl值，栈S[1]~S[n]存储各个权值的编码
    void DisplayAllCoding(LinkStack<char> S[]); //输出各个权值的huffman编码
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
	hufftree[min].parent=0;//避免下一次重复被选
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
//	    S[i].VisitStack();   //栈未弹
		while(!S[i].Empty())
		{
			cout<<S[i].Pop();
			len++;
		}
		cout<<endl;
	}	
}

int main(){
	int w[MaxSize/2],n;//w存储权值，n存储权值个数//={INT_MAX,5,29,7,8,14,23,3,11},n=8;
    string inf[MaxSize];//存储各个权值对应的信息(一个汉字)//={" ","我","爱","你","们","是","好","孩","子"};
    cin>>n;   //输入权值个数
	int i;
	for(i=1;i<=n;i++)
		cin>>w[i];   //输入权值
	for(i=1;i<=n;i++)
		cin>>inf[i];  //输入各个权值对应的汉字
	
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
李 赵 钱 孙 周
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
Coding of 12(李):011
Coding of 35(赵):11
Coding of 17(钱):00
Coding of 7(孙):010
Coding of 22(周):10
WPL=205
*/