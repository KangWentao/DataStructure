//LinkQueueMain.cpp
#include<iostream>       //引用输入输出流
using namespace std;
#include"LinkQueue.cpp"  //引入成员函数文件

void main()
{
    LinkQueue<int> a;         //创建模版类的实例 
    
	if (a.Empty()){
	
		cout<<"队空,对10执行入队操作:\n";
		try
		{
			a.EnQueue(10);             //入队操作
		}
		catch(char* wrong)
		{
			cout<< wrong;
		}
		cout<<"查看队头元素:"<<endl;
		cout<<a.GetQueue( )<<endl;  //读队头元素

		cout<<"对15执行入队操作:"<<endl;
		try
		{
			a.EnQueue(15);
		}
		catch(char* wrong)
		{
			cout<< wrong;
		}
		cout<<"查看队头元素:"<<endl;
		cout<<a.GetQueue()<<endl;

	
		cout<<"执行出队操作:"<<endl;  //出队操作
		a.DeQueue( );              

		cout<<"查看队头元素:"<<endl;
		cout<<a.GetQueue( )<<endl;
	}
	else{
	
		cout<<"队列不空";
	}
	a.~LinkQueue( );
}
