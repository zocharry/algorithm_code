#include <iostream>
#include <stdio.h>	

template<class Type>
int BinarySearch(Type a[],const Type &x, int n){
	int left=0;
	int right=0;
	while(left<=right){
		int middle = (left+right)/2;
		if(x == a[middle]) return middle;
		if(x > a[middle]) left=middle+1;
		else right = middle-1;
	}
	return-1;
}




int main(){
	int m=2;
	int y[4]={};
	for(int i=0;i<=3;i++)
	{
		scanf("%d",&y);
	}
	int p = BinarySearch(y,m,4);
	printf("%d",p);
	return 0;
} 
