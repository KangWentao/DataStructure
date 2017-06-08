#include <iostream>
using namespace std;
const int MaxSize=100;	//˳������󳤶�

//�������
template <class T>
class SortList{
	public:
		SortList(){length=0;}
		~SortList(){}
		void Insert(T x);    //�����Ĳ��룬ʹ����������
 		void DispList();	//�����
	private:
		T data[MaxSize]; //�洢Ԫ��
     	int length;		 //˳���ʵ�ʳ���
};

//��������в���Ԫ��x��ʹ����������
template <class T>
void SortList<T>::Insert(T x){ 
   	int i,j;   	
	if (length>=MaxSize)         //�������ܲ��� 
		throw "Overflow";
	i=1;
	while(i<length+1&&data[i-1]<x)//���Ҳ���λ��
		i++;
   	for (j=length-1;j>=i-1;j--)  //��i���Ժ�λ��Ԫ�غ���
       	data[j+1]=data[j];
    data[i-1]=x;                 //��λ��i����Ԫ��x
   	length++;                    //���Ա�����1   	
}

template <class T>
void SortList<T>::DispList( ){	//������Ա�
   	int i;
	cout<<"The length:"<<length<<endl;
	cout<<"The elements:"<<endl;
   	for (i=1;i<=length;i++)
		cout<<data[i-1]<<" "; 
   	cout<<endl;
}

//���������A����������
template <class T>
void CreateSort(SortList <T> &A);
int main(){

	SortList <int> A; 	
	//����һ�������A
	CreateSort(A);	
	SortList <char> B;
	CreateSort(B);
    A.DispList();
	B.DispList();
	return 0;
}

//���������A����������
template <class T>
void CreateSort(SortList <T> &A){
	int i,n;
	T x;	
	cin>>n;
	for (i=1;i<=n;i++){
		cin>>x;
		try{
			A.Insert(x);
		}
		catch(char *wrong){
			cout<<wrong<<endl;
		}
	}
}