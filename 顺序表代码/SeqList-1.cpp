
#include <iostream>
using namespace std;
const int MaxSize=100;			//˳������󳤶�
template <class T>
class SeqList{
	public:
		SeqList(); //���캯���������ÿ�
		~SeqList(){} //����
		int Locate(T x);  //����Ԫ��x�ڱ��е�λ�ã��ɹ�����x�ڱ��е�λ�ã����򷵻�0
		void Insert(int i, T x);  //�ڱ��iλ�ò���Ԫ��x
		void Reverse();  //�����������
		void DispList();
	private:
		T data[MaxSize];	//�洢Ԫ��
     	int length;		//˳���ʵ�ʳ���
};
  
template <class T>
SeqList<T>::SeqList(){//��ʼ�����Ա�
    length=0;
}

template <class T>
void SeqList<T>::Insert(int i, T x){ //iλ�ò���Ԫ��x

   	int j;
   	if (i<1 || i>length+1)	//����λ�ò��Ϸ�		
       	throw "Illegal position";
	if (length>=MaxSize)      //�������ܲ��� 
		throw "Overflow";
   	for (j=length-1;j>=i-1;j--)	//��i���Ժ�λ��Ԫ�غ���
       	data[j+1]=data[j];
    data[i-1]=x;               //��λ��i����Ԫ��x
   	length++;                  //���Ա�����1
   	
}

template <class T>
void SeqList<T>::DispList(){	//������Ա�

   	int i;
	cout<<"The length:"<<length<<endl;
	cout<<"The elements:"<<endl;
   	for (i=1;i<=length;i++)
		cout<<data[i-1]<<" ";
   	cout<<endl;
}
template <class T>
void SeqList<T>::Reverse(){	//����

   	T temp;
	T *front,*rear;
	for(front=data,rear=data+length-1;front<rear;front++,rear--)
	{
		temp=*front;
		*front=*rear;
		*rear=temp;
	}
}
template <class T>
int SeqList<T>::Locate(T x){
	for (int i=0; i<length; i++)
		if (data[i]==x) return i+1;
	return 0;
}

int main()
{
	SeqList<int> sa;
	int x;
	while(1)
	{
		cin>>x;
        if(!x)break;
		try{
			sa.Insert(1,x);
		}
		catch(char *ms)
		{
			cout<<ms<<endl;
		}
	}
    sa.DispList();
	cin>>x;
	int pos=sa.Locate(x);
	if(!pos) cout<<"No found\n";
	else
		cout<<"Found position:"<<pos<<endl;	
	sa.Reverse();
	sa.DispList();
	return 0;
}
