#include<stdio.h>

template<class Type> 
int BinarySearch(Type a[],const Type&x,int n){
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
	return -1;
}

int main(){
	int *b,n,i;
	int a[10];
	printf("请从大到小输入10个数字：\n");
	for(i=1;i<=10;i++){
		scanf("%d",&a[i-1]);
		printf("\n");
	}
	printf("请输入你要查找的数字：\n");
	scanf("%d",&n);
	i=BinarySearch(a,11,6);
	if(-1==i)
		printf("你要查找的数字不在数组中\n");
	else
		printf("你要查找的数字的数组下标为%d\n",i);
}
