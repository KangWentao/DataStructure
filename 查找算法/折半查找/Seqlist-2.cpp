#include <iostream>
using namespace std;
const int MaxSize=100;	//˳������󳤶�

//�������
class SortList{
	public:
		SortList(){n=0;}
		~SortList(){}
		void Insert(int x);//�����Ĳ��룬ʹ����������
 		void DispList();	//�����
		int Bin_Search(int key);
	private:
		int r[MaxSize+1]; //�洢Ԫ��(r[1]~r[n]�洢Ԫ��)
     	int n;		 //˳���ʵ�ʳ���
};

//��������в���Ԫ��x��ʹ����������
void SortList::Insert(int x){ 
   	int i;   	
	if (n>=MaxSize)         //�������ܲ��� 
		throw "Overflow";
	r[0]=x;
	for(i=n;r[i]>x;i--)
		r[i+1]=r[i];//��iλ��Ԫ�غ���
   	r[i+1]=x;                 //��λ��i+1����Ԫ��x
   	n++;                    //���Ա�����1   	
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

void SortList::DispList( ){	//������Ա�
   	int i;
	cout<<"Data:";
   	for (i=1;i<=n;i++)
		cout<<r[i]<<" "; 
   	cout<<endl;
}

int main(){
	SortList A;  //�ձ�A	
	int x,key;
	//���ò��뺯�������������0����
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
	if(!pos)//����ʧ��
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
