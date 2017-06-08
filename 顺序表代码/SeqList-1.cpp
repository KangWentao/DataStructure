
#include <iostream>
using namespace std;
const int MaxSize=100;			//顺序表的最大长度
template <class T>
class SeqList{
	public:
		SeqList(); //构造函数，将表置空
		~SeqList(){} //析构
		int Locate(T x);  //查找元素x在表中的位置，成功返回x在表中的位置，否则返回0
		void Insert(int i, T x);  //在表的i位置插入元素x
		void Reverse();  //逆序表中数据
		void DispList();
	private:
		T data[MaxSize];	//存储元素
     	int length;		//顺序表实际长度
};
  
template <class T>
SeqList<T>::SeqList(){//初始化线性表
    length=0;
}

template <class T>
void SeqList<T>::Insert(int i, T x){ //i位置插入元素x

   	int j;
   	if (i<1 || i>length+1)	//插入位置不合法		
       	throw "Illegal position";
	if (length>=MaxSize)      //表满不能插入 
		throw "Overflow";
   	for (j=length-1;j>=i-1;j--)	//将i及以后位置元素后移
       	data[j+1]=data[j];
    data[i-1]=x;               //在位置i插入元素x
   	length++;                  //线性表长度增1
   	
}

template <class T>
void SeqList<T>::DispList(){	//输出线性表

   	int i;
	cout<<"The length:"<<length<<endl;
	cout<<"The elements:"<<endl;
   	for (i=1;i<=length;i++)
		cout<<data[i-1]<<" ";
   	cout<<endl;
}
template <class T>
void SeqList<T>::Reverse(){	//逆序

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
