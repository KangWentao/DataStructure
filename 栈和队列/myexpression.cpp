#include <cmath>
#include <iostream>
using namespace std;
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
private:
    T data[StackSize];      //���ջԪ�ص�����
    int top;                //ջ��ָ�룬ָʾջ��Ԫ���������е��±�
};

/*
 * ǰ��������ջ������
 * ��    �룺��
 * ��    �ܣ�ջ�ĳ�ʼ��
 * ��    ������
 * ��������������һ����ջ
 */

template <class T>
SeqStack<T>::SeqStack( )
{
	top=-1;
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ�����ջ
 * ��    ������
 * �����������ͷ�ջ��ռ�õĴ洢�ռ�
 */

template <class T>
SeqStack<T>::~SeqStack( )
{

} 

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺Ԫ��ֵx
 * ��    �ܣ���ջ������һ��Ԫ��x
 * ��    ����������벻�ɹ����׳��쳣
 * �����������������ɹ���ջ��������һ��Ԫ��
 */

template <class T> 
void SeqStack<T>::Push(T x)
{
    if (top== StackSize-1) throw "����";
    top++;
    data[top]=x;
}

/*
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ�ɾ��ջ��Ԫ��
 * ��    �������ɾ���ɹ������ر�ɾԪ��ֵ�������׳��쳣
 * �������������ɾ���ɹ���ջ��������һ��Ԫ��
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
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ���ȡ��ǰ��ջ��Ԫ��
 * ��    ������ջ���գ����ص�ǰ��ջ��Ԫ��ֵ
 * ����������ջ����
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
 * ǰ��������ջ�Ѵ���
 * ��    �룺��
 * ��    �ܣ��ж�ջ�Ƿ�Ϊ��
 * ��    �������ջΪ�գ�����1�����򣬷���0
 * ����������ջ����
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