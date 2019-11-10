#include<stdio.h>
#include<iostream>
using namespace std;

#define Maxsize 100

template<class Type>
int BinarySearch(Type a[],const Type& x, int n){
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])
		 return middle;
		if(x>a[middle])
		 left=middle+1;
		else
		 right=middle-1;
	}
	return-1;
} 
int main(){
	int a[Maxsize];
	int x,j,Length;
	cout<<"输入数组长度"<<endl;
	cin>>Length;
	cout<<"输入数值"<<endl;
	for(int i=0;i<Length;i++)
	 cin>>a[i];
	cout<<"输入需要查找的数"<<endl;
	cin>>x;
	j=BinarySearch(a,x,Length);
	if(j!=-1){
		cout<<"该数在第"<<j+1<<"位"<<endl; 
	}
	else
	 cout<<"未找到该数字"<<endl;
}
