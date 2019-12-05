#include<stdio.h>
#include<iostream>
using namespace std;


int BinarySearch(int a[],const int&x,int n){
	int left=0; int right=n-1;
	while(left<=right){
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


int main()
{
	int a[100],n,x;
	int BinarySearch(int a[],const int&x,int n); 
	cout<<"please input n(n<=100):";
	cin>>n;
	cout<<"Please enter n integers:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	cout<<"Please enter an integer to find:"; 
	cin>>x;
	if(BinarySearch(a,x,n)!=-1)
	  cout<<"x:"<<BinarySearch(a,x,n)+1<<endl;
	else
	   cout<<"not found"<<endl;
	  return 0;   
	
	
}
