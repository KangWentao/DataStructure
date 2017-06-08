#include <iostream>
using namespace std;
const int MaxSize=100;	//顺序表的最大长度

//有序表类
template <class T>
class SortList{
	public:
		SortList(){length=0;}
		~SortList(){}
		void Insert(T x);    //有序表的插入，使序列仍有序
 		void DispList();	//输出表
	private:
		T data[MaxSize]; //存储元素
     	int length;		 //顺序表实际长度
};

//在有序表中插入元素x，使序列仍有序
template <class T>
void SortList<T>::Insert(T x){ 
   	int i,j;   	
	if (length>=MaxSize)         //表满不能插入 
		throw "Overflow";
	i=1;
	while(i<length+1&&data[i-1]<x)//查找插入位置
		i++;
   	for (j=length-1;j>=i-1;j--)  //将i及以后位置元素后移
       	data[j+1]=data[j];
    data[i-1]=x;                 //在位置i插入元素x
   	length++;                    //线性表长度增1   	
}

template <class T>
void SortList<T>::DispList( ){	//输出线性表
   	int i;
	cout<<"The length:"<<length<<endl;
	cout<<"The elements:"<<endl;
   	for (i=1;i<=length;i++)
		cout<<data[i-1]<<" "; 
   	cout<<endl;
}

//构造有序表A：函数声明
template <class T>
void CreateSort(SortList <T> &A);
int main(){

	SortList <int> A; 	
	//生成一个有序表A
	CreateSort(A);	
	SortList <char> B;
	CreateSort(B);
    A.DispList();
	B.DispList();
	return 0;
}

//构造有序表A：函数定义
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