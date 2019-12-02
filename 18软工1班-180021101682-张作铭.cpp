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
	int d;
	scanf("%d",&d);
	int x;
	x=BinarySearch(a,d,6);
	if(x!=-1)
	{
		printf("%d已找到",a[x]);
		
	}
	else
	{
		printf("%d没有找到",a[x]);
	}
	return 0;
}

