#include<iostream> 
#include<cstdio>
#define N 100
using namespace std;

int binarysearch(int a[],int x,int n)
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		if(x<=a[middle])
			right=middle-1;
		else
			left=middle+1;
	}
	return -1;
}
int main()
{
	int num[N],n,x;
	cout<<"size of array?"<<endl;
	cin>>n;
	cout<<"members of array(sorted)"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	} 
	cout<<"find?"<<endl;
	cin>>x;
	int res=binarysearch(num,x,n);
	if(res==-1)
		cout<<"cannot find"<<endl;
	else 
		cout<<"OK!member"<<x<<"locate in"<<res+1<<endl; 
	
	return 0;
}
