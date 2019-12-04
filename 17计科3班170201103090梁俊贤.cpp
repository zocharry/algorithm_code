#include<iostream>
using namespace std;

int BinarySearch(int a[],const int& x,int n)
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		if(x>a[middle])
			left=middle+1;
		else
			right=middle-1;
	}
	return -1;
}

main()
{ 
	int n;
	cout<<"Input a number for the array length"<<endl;
	cin>>n;
	int num[n];
	int i=0;
	int x=0;
	cout<<"Input an array"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>num[i];
	}
	cout<<"Input the number to find in the array"<<endl; 
	cin>>x;
	int p=BinarySearch(num,x,i);
	cout<<"The number position to find is:"<<p;
}
