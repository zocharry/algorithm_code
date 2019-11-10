#include<iostream>
using namespace std;
template<class Type>
int BinarySearch(Type a[],const Type &x ,int n){
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		if(x>middle)
			left=middle+1;
		else
			right=middle-1;	
	}
	return-1;
}

int main(){
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int x;
	cout<<"Please enter the number to find (0-9)\n" ;
	cin>>x; 
	int flag=BinarySearch(a,x,10);
	cout<<"The location is "<<flag;
} 

