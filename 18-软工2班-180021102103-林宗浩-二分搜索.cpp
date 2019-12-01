#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(x==a[mid])
			return mid;
		else if(x>a[mid])
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}

int main()
{
	int m=10010; 
	int y[10]={4,6,11,65,73,81,97,100,10010,10086};
	int p=BinarySearch(y,m,10);
	if(p!=-1)
		cout << "Find it successful£¡" << endl << "The element is located at£º" << p+1 << endl;
	else
		cout << "The element was not found£¡" << endl;
 } 
