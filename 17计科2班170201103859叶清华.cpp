#include<iostream>
using namespace std;

int BinarySearch(int a[], int x, int n)
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		
		for (int i = 0; i < n; i++) 
		{
				cout<<a[i];
				if (i == middle) {
					cout<<"#";
				}
				cout<<" ";
		}
		cout<<endl;
		if(x==a[middle])
			return middle;
		if(x>=a[middle])
			left=middle+1;
		else
			right=middle-1;
	}
	return -1;   
}

int main()
{
	int x=9;
	int array[]={1,3,4,5,6,7,8,9,19,50,61,80};
	int i=BinarySearch(array,x,12);
	cout<<"x="<<x<<" is "<<i<<"th(from 0)";
	if(i<0)
	{
		cout<<"no x"; 
	}
}
