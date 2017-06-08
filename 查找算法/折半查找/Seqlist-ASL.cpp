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
		int Bin_Search(int key);  //返回值为查找key值所需的比较次数
		double ASL_Bin_Search();
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
double SortList::ASL_Bin_Search()
{
	int i,ASL=0;
	for(i=1;i<=n;i++)
		ASL+=Bin_Search(r[i]);  //累加各个元素所需的比较次数
    return 1.0*ASL/n;
}

//查找元素key所需的比较次数	
int SortList::Bin_Search(int key)
{
	int low,high,count=0;
	low=1;
	high=n;
	while(low<=high)
	{
		int mid=(low+high)/2;
		count++;
		if(r[mid]==key) return count;
		else if(r[mid]>key) high=mid-1;
		else low=mid+1;
		
	}
	return count;
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
	int x;
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
	double ASL;
	ASL=A.ASL_Bin_Search();
	cout<<"ASL:"<<ASL<<endl;
	return 0;
}
/*
43 53 1 25 2 426 324 345 423 34 0
Data:1 2 25 34 43 53 324 345 423 426
ASL:2.9

43 53 1 25 2 426 324 345 423 34 120 0
Data:1 2 25 34 43 53 120 324 345 423 426
ASL:3
*/
