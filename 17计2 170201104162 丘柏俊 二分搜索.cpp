#include <stdio.h> 

int BinarySearch(int a[],const int &x,int n){
	int left=0,right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])return middle;
		if(x>a[middle]) left=middle+1;
		else right=middle-1;
	}
	
	return -1;
}
int main(){
	int a[]={2,4,8,9,11,12,13,15,18,20,25,30};
	int n=sizeof(a) ;
	printf("%d\n",BinarySearch(a,13,n));
	return 0;
}
