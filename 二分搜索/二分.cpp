#include<stdio.h>
template<class Type>
int BianrySearch(Type a[],const Type& x,int n){ //二分法的函数 
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
int main(){
	int a[5]={12,23,56,138,267},x=23,n=5,i;//定义个由小到大排好的数组  要查的数 和长度 
	i=BianrySearch(a,x,n);//找到23的位置 
	printf("%d",i+1);//输出结果 
}
