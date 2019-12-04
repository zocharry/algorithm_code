#include <iostream>
using namespace std;
int BinarySearch(int a[],int x,int n){
	int left=0; int right= n-1;
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

int main(){
	int s[10]={1,11,8,9,25,78,10,2,5,12};
	cout<<"25 is in s["<<BinarySearch(s,25,10)<<"]";
	return 0;
}
