#include <iostream>
using namespace std;
const int MaxSize=100;	//顺序表的最大长度

//有序表类
class SortList{
	public:
		SortList(){n=0;}
		~SortList(){}
		void Insert(int x);//有序表的插入，使序列仍有序
 		void DispList();	//输出表
		int Bin_Search(int key);
	private:
		int r[MaxSize+1]; //存储元素(r[1]~r[n]存储元素)
     	int n;		 //顺序表实际长度
};

//在有序表中插入元素x，使序列仍有序
void SortList::Insert(int x){ 
   	int i;   	
	if (n>=MaxSize)         //表满不能插入 
		throw "Overflow";
	r[0]=x;
	for(i=n;r[i]>x;i--)
		r[i+1]=r[i];//将i位置元素后移
   	r[i+1]=x;                 //在位置i+1插入元素x
   	n++;                    //线性表长度增1   	
}

int SortList::Bin_Search(int key)
{
	int low,high;
	low=1;
	high=n;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(r[mid]==key) return mid;
		else if(r[mid]>key) high=mid-1;
		else low=mid+1;
	}
	return 0;
}

void SortList::DispList( ){	//输出线性表
   	int i;
	cout<<"Data:";
   	for (i=1;i<=n;i++)
		cout<<r[i]<<" "; 
   	cout<<endl;
}

int main(){
	SortList A;  //空表A	
	int x,key;
	//利用插入函数创建有序表，以0结束
	while(1){
		cin>>x;
		if(!x)break;
		try{
			A.Insert(x);
		}
		catch(char *wrong){
			cout<<wrong<<endl;
		}
	}
	A.DispList();
	int pos;
	cin>>key;
	pos=A.Bin_Search(key);
	if(!pos)//查找失败
		cout<<"Find "<<key<<" failure\n";
	else cout<<"Find "<<key<<" success,position:"<<pos<<endl;

	return 0;
}
/*
43 53 1 25 2 426 324  345 423 34 0 25
Data:1 2 25 34 43 53 324 345 423 426
Find 25 success,position:3


43 53 1 25 2 426 324 345 423 34 0 33
Data:1 2 25 34 43 53 324 345 423 426
Find 33 failure

*/
