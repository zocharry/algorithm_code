#include <stdio.h>
int main(){
	int a[100];
	int n,x;
	int left=0,right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle]) return a[middle];
		else if(x<a[middle]) right=middle;
		else if(x>a[middle]) left=middle;
		else return 0;
	}

	return 0;
}

