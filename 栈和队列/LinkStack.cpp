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
    LinkStack( );              //���캯�����ÿ���ջ
    ~LinkStack( );             //�����������ͷ���ջ�и����Ĵ洢�ռ�
    void Push(T x);           //��Ԫ��x��ջ
    T Pop( );                  //��ջ��Ԫ�س�ջ
    T GetTop( );               //ȡջ��Ԫ�أ�����ɾ����
    bool Empty( );             //�ж���ջ�Ƿ�Ϊ��ջ
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
