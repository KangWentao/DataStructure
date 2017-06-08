
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
	  
		/*成员函数Merge实现两个有序表的合并，使序列仍有序，
		即：将A表和B表合并到当前类中，要求A,B表数据元素保持不变*/		
		void Merge(SortList <T> &A,SortList <T> &B);
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

//实现两个有序表的合并(若形参为常成员对象，则只能调用常成员函数，且其数据成员不能修改
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

//构造有序表A：函数声明
template <class T>
void CreateSort(SortList <T> &A);
int main(){

	SortList <int> A,B,C; 	
	//生成一个有序表A
	CreateSort(A);
	//生成一个有序表B
	CreateSort(B);	
	try{
		C.Merge(A,B);//合并A,B表为C表	    
	}		
    catch(char* wrong){
		cout << wrong;    //如失败提示失败信息
	}
    A.DispList();
	B.DispList(); 
	C.DispList();  //显示合并后的结果
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