
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
	  
		/*��Ա����Mergeʵ�����������ĺϲ���ʹ����������
		������A���B��ϲ�����ǰ���У�Ҫ��A,B������Ԫ�ر��ֲ���*/		
		void Merge(SortList <T> &A,SortList <T> &B);
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

//ʵ�����������ĺϲ�(���β�Ϊ����Ա������ֻ�ܵ��ó���Ա�������������ݳ�Ա�����޸�
template <class T>
void SortList<T>::Merge(SortList <T> &A,SortList <T> &B){
	
    if (A.length+B.length>MaxSize) 
		throw "Overflow\n"; 
	int *pa,*pb,*pc;
	pc=data;
	length=A.length+B.length;
	for(pa=A.data,pb=B.data;pa<A.data+A.length&&pb<B.data+B.length;)
		if(*pa<*pb) *pc++=*pa++;
		else *pc++=*pb++;
    for(;pa<A.data+A.length;)
		*pc++=*pa++;
	for(;pb<B.data+B.length;)
		*pc++=*pb++;

}

//���������A����������
template <class T>
void CreateSort(SortList <T> &A);
int main(){

	SortList <int> A,B,C; 	
	//����һ�������A
	CreateSort(A);
	//����һ�������B
	CreateSort(B);	
	try{
		C.Merge(A,B);//�ϲ�A,B��ΪC��	    
	}		
    catch(char* wrong){
		cout << wrong;    //��ʧ����ʾʧ����Ϣ
	}
    A.DispList();
	B.DispList(); 
	C.DispList();  //��ʾ�ϲ���Ľ��
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