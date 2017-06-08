//LinkStack.cpp
#include <iostream>
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

int main()
{
	LinkStack<char> s;
	char ch;
	while(1)
	{
		cin>>ch;
		if(ch=='#') break;
		s.Push(ch);		
	}
	cout<<"Gettop:"<<s.GetTop()<<endl;
	while(!s.Empty())
	{
		cout<<s.Pop()<<" ";
	}
	cout<<endl;
	try{
		cout<<"Gettop:"<<s.GetTop()<<endl;
	}
	catch(const char *ms){
		cout<<"Gettop:"<<ms<<endl;
	}
	return 0;
}
