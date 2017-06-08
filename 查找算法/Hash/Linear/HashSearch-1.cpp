#include<iostream>         
using namespace std;
const int MaxSize=11; //hash表的表长，即教材中的m
class HashList
{
private:
	int ht[MaxSize]; // hashtable
public:
	int HashFunc(int k);  //hash function
	HashList();     //consturctor
	void Display();      //display 
	int HashSearch(int k);  //dynamic search k
	double HashASL();   //search ASL
};

//hash function
int HashList::HashFunc(int k)
{
	return k%11;   //hash函数，假设为除余法，余数为11
}

//constructor:initialize an empty hashlist
HashList::HashList()
{
	int i;
	for(i=0;i<MaxSize;i++)
		ht[i]=-1;  //-1 is empty
}
void HashList::Display()
{
	int i;
	for(i=0;i<MaxSize;i++)
		cout<<ht[i]<<" ";
	cout<<endl;
}
int  HashList::HashSearch(int k) //return times of comparing
{
	int hashadd=HashFunc(k);  //hash address
	int hashinc,newadd;
	for(hashinc=0;hashinc<MaxSize;hashinc++)
	{
		newadd=(hashadd+hashinc)%MaxSize;
		if (ht[newadd]==-1) {//查找不成功时插入
			ht[newadd]=k;
			return hashinc+1;
		}
		else if (ht[newadd]==k) return hashinc+1;  //found k,insert failure
	}
    throw"Overflow";  //full
}
double  HashList::HashASL() 
{
	double ASL=0;
	int i,n=0;
	for(i=0;i<MaxSize;i++)
		if(ht[i]!=-1)
		{
			ASL+=HashSearch(ht[i]);
			cout<<ht[i]<<" "<<HashSearch(ht[i])<<endl;
			n++;
		}
	return ASL/n;
}

int main()
{
    HashList HL;
//	HL.Display();
	while(1)
	{
		int k;
		cin>>k;
		if(!k) break;
		try{
			HL.HashSearch(k); 
		}
		catch(const char *ms)
		{
			cout<<ms<<endl;
		}
	}
	HL.Display();  
	cout<<"ASL="<<HL.HashASL();
	return 0;
}

/*
47 7 29 11 16 92 22 8 3 29 0
11 22 -1 47 92 16 3 7 29 8 -1
11 1
22 2
47 1
92 1
16 1
3 4
7 1
29 2
8 2
ASL=1.66667

47 7 29 11 16 92 22 8 3 22 19 30 0
11 22 30 47 92 16 3 7 29 8 19
11 1
22 2
30 6
47 1
92 1
16 1
3 4
7 1
29 2
8 2
19 3
ASL=2.18182
*/