#include<stdio.h>
 

int BinarySearch(int a[],int x,int n)
{
	int left=0; 
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(x==a[middle]) return middle;
		if(x>a[middle])  return left=middle+1;
		else right=middle-1;
	}
	return -1;
}
int main()
{
	//char m='h';
	//char y[5]={'j','h','g','f','d'};
	int m, y[100];
	int n,i;
	printf("请输入数组长度：\n");
	scanf("%d",&n);
	printf("请输入数组元素：\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&y[i]);
	}
	printf("请输入你要查找的元素: \n");
	scanf("%d",&m);
	
    int p=BinarySearch(y,m,n);
    if (p!=-1) printf("查找成功！%d在数组y[%d]的位置上",m,p);
    else printf("查找失败！");
    return 0;
}

