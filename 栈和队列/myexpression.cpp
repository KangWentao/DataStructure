#include <cmath>
#include <iostream>
using namespace std;
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
    if (top== StackSize-1) throw "上溢";
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
    if (Empty()) throw "stack empty, downflow!";
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
		throw "stack empty,downflow!";
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
	if(top==-1) return 1;
	else return 0;
} 


//priority level 
char optrs[]={'+','-','*','/','%','(',')','#'};

static int prio[8][8]
     ={{1,1,-1,-1,-1,-1,1,1},
       {1,1,-1,-1,-1,-1,1,1},
       {1,1,1,1,1,-1,1,1},
       {1,1,1,1,1,-1,1,1},
       {1,1,1,1,1,-1,1,1},
       {-1,-1,-1,-1,-1,-1,0,2},
       {2,2,2,2,2,2,2,2},
       {-1,-1,-1,-1,-1,-1,2,0}};

int Locate(char s[],char ch)
{
	for(int pos=0;s[pos]!=0;pos++)
		if(s[pos]==ch) 
			return pos;
	return -1;
}

template <class T>
T Calculate(T x, T y, char op){
	switch(op){
	case '+':
		return x+y;
	case '-':
		return x-y;
	case '*':
		return x*y;
	case '/':
	    if (y==0) throw "divided by zero";
		return x/y;
	case '%':
		return x%y;
	default:
		throw "calculate syntax error !";
	}
}

void Preprocess(char exp[])
{
	char *p;
	p=exp;
	while(*p) p++;
    *(p+2)='\0';
	*(p+1)='#';
	while(p>exp)
		*p--=*(p-1);
	*p='#';		
}

void Postprocess(char exp[])
{
	char *p,*q;
    p=exp;
	q=exp;
	while(*q)
		if(*q==' '||*q=='#') q++;
		else *p++=*q++;
	*p='\0';
}

double CalExpress(char exp[]){

	Preprocess(exp);
//	cout<<exp<<endl;
	SeqStack <int> opnd;
	SeqStack <char>optr;
	optr.Push('#');
	int pos=1;
//    strcat(exp,"#");
	while(exp[pos]){
     	while(exp[pos]==' ') pos++;
        int col=Locate(optrs,exp[pos]);
		if (col!=-1){            
	//		cout<<exp[pos]<<endl;
			int vol=Locate(optrs,optr.GetTop());
			int x,y;
			char op;
			if(vol==-1) throw "gettop syntax error!";
			else 
				switch(prio[vol][col]){
				case -1: 
					optr.Push(exp[pos++]);
					break;
				case 1:
					op=optr.Pop();
					y=opnd.Pop();
					x=opnd.Pop();
					opnd.Push(Calculate(x,y,op));
					break;
				case 0:
					op=optr.Pop();
					pos++;
					break;
				default: throw"prior syntax error!";
			}

		}
		else{
			int num=0;
	//		double base;
			bool flag=false;
			while(exp[pos]>='0'&&exp[pos]<='9')
			{
				num=10*num+exp[pos++]-'0';
				flag=true;
			}
		/*	if (exp[pos]=='.'){
				base=10;
				pos++;
                while(exp[pos]>='0'&&exp[pos]<='9'){
					num=num+(exp[pos++]-'0')/base;
			//		cout<<(exp[pos-1]-'0')/base;
					base*=10;
					flag=true;
				}
			}
	//		cout<<num<<endl;*/
			if (flag) opnd.Push(num);
			else throw"illegal char syntax error!";
          //  while(exp[pos]==' ') pos++;
		}	
	}
	Postprocess(exp);
	double result=opnd.Pop();
	if(opnd.Empty()) return result;
	else throw "operator syntax error!";
}

int main(){
	char expression[80];//="3*(4/10+ .0)  / 5";//"45   67";//"+";//"(3+45)89";//"3*(4/10+ .0)  / 5"//"45 67";
	int result;
	cin>>expression;
	try{
		result=CalExpress(expression);
//		cout<<expression<<"="<<result<<endl;
		cout<<result<<endl;
	}
	catch(const char *mess){
		cout<<mess<<endl;
	}
//	cout<<Calculate(2,13.5,'*');
//	getchar();
	return 0;
}