#include <iostream>
using namespace std;
const int StackSize=5;  //顺序栈的最大长度（请勿改动）
template <class T>       //定义模板类SeqStack
class SeqStack
{
public:
    SeqStack( ) ;            //构造函数，栈的初始化
	~SeqStack( );            //析构函数
    void Push(T x);          //将元素x入栈
    T Pop( );                //将栈顶元素弹出
    T GetTop( );	         //取栈顶元素（并不删除）
	bool Empty( );           //判断栈是否为空
private:
    T data[StackSize];      //存放栈元素的数组
    int top;                //栈顶指针，指示栈顶元素在数组中的下标
};

/*
 * 前置条件：栈不存在
 * 输    入：无
 * 功    能：栈的初始化
 * 输    出：无
 * 后置条件：构造一个空栈
 */

template <class T>
SeqStack<T>::SeqStack( )
{
	top=-1;
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：销毁栈
 * 输    出：无
 * 后置条件：释放栈所占用的存储空间
 */

template <class T>
SeqStack<T>::~SeqStack( )
{

} 

/*
 * 前置条件：栈已存在
 * 输    入：元素值x
 * 功    能：在栈顶插入一个元素x
 * 输    出：如果插入不成功，抛出异常
 * 后置条件：如果插入成功，栈顶增加了一个元素
 */

template <class T> 
void SeqStack<T>::Push(T x)
{
    if (top== StackSize-1) throw "Overflow";
    top++;
    data[top]=x;
}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：删除栈顶元素
 * 输    出：如果删除成功，返回被删元素值，否则，抛出异常
 * 后置条件：如果删除成功，栈顶减少了一个元素
 */     

template <class T>
T SeqStack<T>::Pop( )
{ 
    T x;
    if (top==-1) throw "Downflow";
    x=data[top--];
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
T SeqStack<T>::GetTop( )
{
	if (!Empty())  
		return data[top];
	else 
		throw"Downflow";

}

/*
 * 前置条件：栈已存在
 * 输    入：无
 * 功    能：判断栈是否为空
 * 输    出：如果栈为空，返回1，否则，返回0
 * 后置条件：栈不变
 */

template <class T> 
bool SeqStack<T>::Empty( )
{
	return top==-1;
} 

int main()
{
	SeqStack<int> s;
	int x;
	while(1)
	{
		cin>>x;
		if(!x) break;
		try{
			s.Push(x);
		}
		catch(const char *ms){
			cout<<"Push:"<<ms<<endl;
		}
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
