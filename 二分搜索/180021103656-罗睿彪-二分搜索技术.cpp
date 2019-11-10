#include<iostream>
using namespace std;
template<class Type>
int BinarySearch(Type a[],const Type& x,int n){
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
int main()
{
	char m='h';
	char y[4]={'a','b','h','g'};
	int w;
	int p=BinarySearch(y,m,4);
	cout<<"The place is "<<p+1;
	return 0;
}


