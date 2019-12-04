#include<iostream>
using namespace std;
 
int a[100];
int x;
 
int BinarySearch(int a[],int x,int n)
{//找到x时返回其在数组的位置，否则返回-1 
	int left=0,right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		if(x<a[middle])
			right=middle-1;	
		else
			left=middle+1;
	}
	return -1;//未找到x 
}
int main()
{
	int n;
	cin>>n;//n个数 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	cin>>x;//要找的数 
	cout<<BinarySearch(a,x,n)<<endl;
	return 0;	
}
