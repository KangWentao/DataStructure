#include<iostream>
using namespace std;
//栈类
const int StackSize=100;  //10只是示例性的数据，可以根据实际问题具体定义
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
	bool Full();             //判断栈是否为满
private:
    T data[StackSize];      //存放栈元素的数组
    int top;                //栈顶指针，指示栈顶元素在数组中的下标
};

//初始化空栈
template <class T>
SeqStack<T>::SeqStack( )
{
	top=-1;
}

//功    能：销毁栈
template <class T>
SeqStack<T>::~SeqStack( )
{
} 

//功    能：元素x压栈
template <class T> 
void SeqStack<T>::Push(T x)
{
    if (Full()) throw "Overflow";
    top++;
    data[top]=x;
}
// 功    能：栈顶元素弹栈
template <class T>
T SeqStack<T>::Pop( )
{ 
    T x;
    if (Empty()) throw "Downflow";
    x=data[top--];
    return x;
}

// 功    能：读取当前的栈顶元素
template <class T> 
T SeqStack<T>::GetTop( )
{
	if (Empty())throw"Downflow";  
    return data[top];
}

//功    能：判断栈是否为空
template <class T> 
bool SeqStack<T>::Empty( )
{
	return top==-1;
} 

//功    能：判断栈是否为满
template <class T> 
bool SeqStack<T>::Full( )
{
	return top==StackSize-1;
} 
//顺序表类
const int MaxSize=100;
class List
{
private:
	int r[MaxSize+1];
	int n;
public:
    List(){n=0;} //empty list
	void InsertR(int k)  //表尾插入
	{  r[++n]=k;}
	void Display();      //display
	void QuickSort();   //quickSort
	void QuickSort2();
};

//快速排序
void List::QuickSort()
{
	SeqStack<int> S;
//	int first, int end;
	if(n>1){S.Push(n);S.Push(1);}
	while(!S.Empty())
	{
         //一次划分
		int first=S.Pop();//first;                        //初始化
		int end=S.Pop();//end;
	//	if(first<end) {//下面语句}
		int i=first;
		int j=end;
		r[0]=r[i];
		while (i<j)	
		{  
			while (i<j && r[j]>=r[0])
				j--;                        //右侧扫描
			r[i]=r[j];                 //将较小记录交换到前面
			while (i<j && r[i]<=r[0]) 
				i++;                         //左侧扫描
			r[j]=r[i]; //将较大记录交换到后面	  
		}
		r[i]=r[0];
		if(i+1<end)
		{
			S.Push(end);
			S.Push(i+1);
		}
		if(first<i-1)
		{
			S.Push(i-1);
			S.Push(first);
		}
	}
}
void List::QuickSort2()
{
	SeqStack<int> S;
//	int first, int end;
	S.Push(n);S.Push(1);
	while(!S.Empty())
	{
		//一次划分
		int first=S.Pop();//first;                        //初始化
		int end=S.Pop();//end;
		if(first<end) 
		{//下面语句
			int i=first;
			int j=end;
			r[0]=r[i];
			while (i<j)	
			{  
				while (i<j && r[j]>=r[0])
					j--;                        //右侧扫描
				r[i]=r[j];                 //将较小记录交换到前面
				while (i<j && r[i]<=r[0]) 
					i++;                         //左侧扫描
				r[j]=r[i]; //将较大记录交换到后面	  
			}
			r[i]=r[0];
			S.Push(end);
			S.Push(i+1);
			S.Push(i-1);
			S.Push(first);
		}
	}
}
void List::Display()
{
	for(int i=1;i<=n;i++)
       cout<<r[i]<<" ";	  
	cout<<"\n";
}
int main()
{
	List L;
	while(1)
	{
		int k;
		cin>>k;
		if(!k) break;
        L.InsertR(k);
	}
	L.Display();
	L.QuickSort();
	L.Display();
	return 0;
}

/*
12 21 32 2 4 24 21 432 23 9 0
12 21 32 2 4 24 21 432 23 9 
2 4 9 12 21 21 23 24 32 432 

12 21 32 2 4 24 21 432 23 9 88 76 35 0
12 21 32 2 4 24 21 432 23 9 88 76 35 
2 4 9 12 21 21 23 24 32 35 76 88 432 

  */