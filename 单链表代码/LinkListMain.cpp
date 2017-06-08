//LinkListMain.cpp
#include "base.h"
#include "base.cpp"
#include "LinkList.h"
#include "LinkList.cpp"  //引用单链表的类
void main( ){
	int i,choi;
	int x;
        LinkList <int> A; //normal list1   
	
	do{
		cout<<"\n 0 exit       1 Insert       2 Delete \n";
		cout<<" 3 Get(i)     4  Locate(x)   5 Exchange\n";
		cout<<" 6 Divide     7  DispList"<<endl;
		cout<<" 8 Create a sorted list, then display\n";
		cout<<" please choice..."<<endl;
		cin>>choi;		
		try{
			switch(choi){
			case 0:
				break;
			case 1:	
                cout<<"Input the position and an element\n";
				cin>>i>>x;
				A.Insert(i,x);			
				break;
			case 2:
				cout<<"Input the position of the deleted element\n";
				cin>>i;
				A.Delete(i);
				break;
			case 3:
                cout<<"Input the position of the searched element\n";
				cin>>i;
				x=A.Get(i);
				cout<<"Element of i:"<<x<<endl;
				break;
			case 4:
                cout<<"Input the located element\n";
				cin>>x;
				i=A.Locate(x);
				cout<<"Position of x: "<<i<<endl;
				break;
			case 5:
				A.Exchange();
				break;
			case 6:
				{
					LinkList <int> B;
					Divide(A,B);
					A.DispList();
					B.DispList();
				}
				break;
			case 7:
				A.DispList();
				break;
			case 8:
				{
					LinkList<int> B, C;
					cout<<"Input 5 data(int): ";
					for (i=1;i<=5;i++){
						cin>>x;
						B.Insert(x);
					}
					B.DispList();
					cout<<"Input 5 data(int): ";
					for (i=1;i<=5;i++){
						cin>>x;
						C.Insert(x);
					}
					C.DispList();
					Merge(B,C);
					B.DispList();
				}
				break;
				
			default:
				throw "Choice error";
			}
		}
		catch(char *wrong){
			cout<<wrong<<endl;
		}
	}while(choi);
}