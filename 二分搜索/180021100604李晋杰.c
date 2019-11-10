#include<stdio.h>
int BinSearch(int a[],int num,int n){
	int left=0,mid,right;
	right=num-1;
	while(left<=right){
		mid=(left+right)/2;
		if(a[mid]==n)
			return mid;
		if(a[mid]<n)
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}

	void main(){
	int a[]={2,3,4,5,8,9,10,11,16};
	int i,n,addr;
	printf("the array is:\n");
	for(i=0;i<sizeof(a)/sizeof(int);i++)
		printf("%-4d,a[i]");
	printf("\nsearch nuber is:");
	scanf("%d",&n);
	addr=BinSearch(a,sizeof(a)/sizeof(int),n);
	if(addr==-1)
		printf("can't find");
	else
		printf("the %d is %dth at the arry.\n",n,addr);
}
