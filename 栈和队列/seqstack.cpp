#include <iostream>
using namespace std;
const int StackSize=5;  //˳��ջ����󳤶ȣ�����Ķ���
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
    if (top== StackSize-1) throw "Overflow";
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
    if (top==-1) throw "Downflow";
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
		throw"Downflow";

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
