//SeqStack.cpp

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
    if (top==-1) throw "����";
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
	if (top!=-1)  
    return data[top];
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



int fact(int n){
    if (n<0) throw "error";
     if (n==0||n==1) return 1;
     SeqStack <int> S;  
     int f=1;
     do{
            if (n>1) S.Push(n--);
            else { 
                      int x=S.Pop();
                      f=f*x;
            }           
     }while(!S.Empty());
     return f;
}


bool Judge(string  str){
	int i=0; 
	SeqStack <char>S;  
	char x;	
	while(str[i]!='\0'){
		if (str[i]=='(' )
		{
			S.Push(str[i]);
		//	cout<<" Push: "<<str[i];
		}
		else if (str[i]==')' )
			if (S.Empty()) return false;
			else 
			{
				x=S.Pop( );
			//	cout<<" Pop: "<<x;
			}
		i++;
	}
    if (S.Empty()) return true;   //matched
	else return false;
} 
