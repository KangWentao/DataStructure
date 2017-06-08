#include <iostream>
using namespace std;
int main()
{
	int m,n,i;
	int a[100];
	cin>>n>>m;
	for(i=0;i<n;i++)
		a[i]=i+1;
    int pos=-1;
	for(int count=n;count;count--)
	{
		for(i=1;i<=m;)
		{	pos=(pos+1)%n;
		    if(a[pos])i++;			
		}
		cout<<a[pos]<<" ";
		a[pos]=0;
	}
	return 0;
}

/*int i,j,m,n,a=0;;
	cin>>m>>n;
	int A[100];
	for(i=0;i<n;i++)
		A[i]=i+1;
	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			if(a==n) a=0;
			if(A[a]==0) i--;
			a++;
		}
		cout<<A[a-1];
		A[a-1]=0;
	}*/