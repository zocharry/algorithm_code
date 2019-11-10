#include <stdio.h>
#include <stdlib.h>
#include <iostream>
    int BinarySearch(int a[], const int x,int n){ 
    int left=0; int right=n;
    while (left <= right){
	int mid = (left + right) / 2;
    if (x > a[mid])
    {
        left=mid+1;
    }    
    else if (x < a[mid])
    {
        right=mid-1;
    }else{
    	return mid;
	}
    }
    return -1;
} 
int main(int argc, const char * argv[])
{
	int a[]={1 ,4 , 6, 8, 19, 34, 93};
	int n = sizeof(a)/sizeof(int);
	int x = 34;
	for(int i = 0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n查找的数字是:%d\n",x);
	int xiabiao = BinarySearch(a, x, n);
	if (xiabiao == -1) {
		printf("不存在的\n");
	}else{
		printf("在数组中下标:%d",xiabiao);
    }
    return 0;
} 
