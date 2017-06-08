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
	void QuickSort(int first,int end);   //quickSort
	void QuickSort()
	{
		QuickSort(1,n);
	}
};

//��������
void List::QuickSort(int first, int end)
{
    if (first<end)  //else �ݹ����
	{      //һ�λ���
		int i=first;                        //��ʼ��
		int j=end;
		r[0]=r[i];
		while (i<j)	
		{  
			while (i<j && r[j]>=r[0])
				j--;                        //�Ҳ�ɨ��
			r[i]=r[j];                 //����С��¼������ǰ��
			while (i<j && r[i]<=r[0]) 
				i++;                         //���ɨ��
			r[j]=r[i]; //���ϴ��¼����������	  
		}
		r[i]=r[0];
		QuickSort(first, i-1);//�ݹ�ض���������н��п�������
		QuickSort(i+1, end);  //�ݹ�ض��Ҳ������н��п�������
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
	L.QuickSort();
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