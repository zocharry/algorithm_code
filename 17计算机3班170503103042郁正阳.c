#include <stdio.h> 
#include <stdlib.h> 
//template <class Type>
int BinarySearch(int *a, int x)
{
	int left=0;
	int right=9; 
	while(left<=right)
	{
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
void main()
{ 
	int *a,x,i; 
	int b[10]={0}; 
	a=b; 
	printf("请输入从小到大10个整数:\n"); 
	for(i=1;i <=10;i++) 
	{ 
		scanf("%d",&b[i-1]); 
		printf("\n"); 
	} 
		printf("你要查找的数:\n"); 
		scanf("%d",&x); 
	if(!BinarySearch(a,x))
		printf("你要查找的数不存在\n"); 
	else
		printf("你要查找的数的下标为 %d \n",BinarySearch(a,x)); 
} 

