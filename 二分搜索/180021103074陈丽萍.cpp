//分治法求二分搜索 
#include<stdio.h>
template<class Type>
int BinarySearch(Type a[],const Type& x, int n){
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle]){
			printf("这个数的位置第%d个\n",middle+1);break;
		}
		else{
			if(x>a[middle])
			    left=middle+1;
		    else
				right=middle-1;
		}	
	}
	if(left>right)
		printf("没有找到这个数\n");
}
int main(){
	int i,n,x;
	printf("请输入5个有序的数：\n");
	int a[5];
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	printf("请输入要查找的数\n");
	scanf("%d",&x);
	BinarySearch(a,x,5);
	return 0;
}
