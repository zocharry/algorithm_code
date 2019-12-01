#include<stdio.h>
template<class Type>
int BinarySearch(Type a[],const Type&x, int n)
{
	int left=0;int right =n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		else if(x>a[middle])
			left=middle+1;
		else 
			right=middle-1;			
	}
	return -1; 
}
int main()
{
	int a[]={1,3,7,10,15,20};
	printf("请输入你要寻找的数字：");
	int s;
	scanf("%d",&s);
	int x;
	x=BinarySearch(a,s,6);
	if(x!=-1)
	{
		printf("%d已找到在第%d个",a[x],x+1);
		
	}
	else
	{
		printf("%d没有找到",a[x]);
	}
	return 0;
}

