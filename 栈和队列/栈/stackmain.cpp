#include "seqstack.h"
#include "seqstack.cpp"
#include <string>
void main(){
     int choi; 
	 int x;
	 string str;
     SeqStack <int>S;
     do{
        cout<<"\n 0 exit 1 Push 2 Pop 3 Judge 4 Factorial\n";
        cin>>choi;  //分支选项
        switch(choi){
			case 0:
				break;
			case 1:
				cin>>x;
				S.Push(x);
				break;
			case 2:
				if(!S.Empty()){
					x=S.Pop();
					cout<<"Pop: "<<x;
				}
				else cout<<"Stack is empty"<<endl;
				break;
			case 3:				
				cout<<"Input an  expression:";
				cin>>str; 
				if(Judge(str)) 
					cout<<" The expression is matched"<<endl;
				else 
					cout<<" \nSyntax error!";
				break;
			case 4:
				int n,fac;
				cout<<"Input an int: ";
				cin>>n;
				try{fac=fact(n);}
				catch(char *message){
					cout<<message;
				}
				if (n>=0)
					cout<<n<<"!= "<<fac;
				break;
			default: 
				cout<<"Selection is error,Try again!"<<endl;
		}
	 }while(choi);
}//end of main
