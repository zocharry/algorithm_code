#include<stdio.h>
int main(){
	int i=0,b,c,d,t,g;
	int a[i];
	printf("请10个输入所需排序的数字：");
	for(b=0;b<10;b++)
	{
		scanf("%d",&a[i]);
		i++;
	}
	for(c=0;c<9;c++){
		for(d=0;d<9-c;d++)
		{
			if(a[d]>a[d+1]){t=a[d];a[d]=a[d+1];a[d+1]=t;}
		} 
	}
	printf("输入后由小到大的排序：");
	for(c=0;c<10;c++){
		printf("%d",a[c]);
		printf("\t");
	}
	printf("\n");
	printf("请输入所需查找数目：");
	scanf("%d",&g);
	Search(a,g);	
	return 0;
} 
int Search(int c[],int x)
{	
	int low=0,high=9,mid;
	
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x==c[mid])
		{printf("查找成功!");break;}
		else if(x<c[mid])high=mid-1;
		else low=mid+1;
	}
	if(low>high)
	{printf("查找失败！");}

	return 0;
	
	
	
} 











