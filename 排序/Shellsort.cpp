#include<iostream>
using namespace std;
const int MaxSize=100;
class List
{
private:
	int r[MaxSize+1];
	int n;
public:
    List(){n=0;} //empty list
	void InsertR(int k)  //��β����
	{  r[++n]=k;}
	void Display();      //display
	void ShellSort();   //ShellSort
};
//ϣ������
void List::ShellSort()
{	
	int i;
	int d;
	int j;
    for (d=n/2; d>=1; d=d/2)            //������Ϊd����ֱ�Ӳ�������
	{
	     for (i=d+1; i<n; i++)   
		 {   
             r[0]=r[i];                 //�ݴ汻�����¼
               for (j=i-d; j>0 && r[0]<r[j]; j=j-d)
                     r[j+d]=r[j];       //��¼����d��λ��
                          r[j+d]=r[0];
		 }
	}	
}
void List::Display()
{
	for(int i=1;i<=n;i++)
       cout<<r[i]<<" ";	  
	cout<<"\n";
}
int main()
{
	List L;
	while(1)
	{
		int k;
		cin>>k;
		if(!k) break;
        L.InsertR(k);
	}
	L.Display();
	L.ShellSort();
	L.Display();
	return 0;
}

/*
12 21 32 2 4 24 21 432 23 9 0
12 21 32 2 4 24 21 432 23 9 
2 4 9 12 21 21 23 24 32 432 

12 21 32 2 4 24 21 432 23 9 88 76 35 0
12 21 32 2 4 24 21 432 23 9 88 76 35 
2 4 9 12 21 21 23 24 32 35 76 88 432 

  */