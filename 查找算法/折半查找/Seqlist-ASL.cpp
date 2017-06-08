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
		int Bin_Search(int key);  //����ֵΪ����keyֵ����ıȽϴ���
		double ASL_Bin_Search();
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
double SortList::ASL_Bin_Search()
{
	int i,ASL=0;
	for(i=1;i<=n;i++)
		ASL+=Bin_Search(r[i]);  //�ۼӸ���Ԫ������ıȽϴ���
    return 1.0*ASL/n;
}

//����Ԫ��key����ıȽϴ���	
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

void SortList::DispList( ){	//������Ա�
   	int i;
	cout<<"Data:";
   	for (i=1;i<=n;i++)
		cout<<r[i]<<" "; 
   	cout<<endl;
}

int main(){
	SortList A;  //�ձ�A	
	int x;
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
