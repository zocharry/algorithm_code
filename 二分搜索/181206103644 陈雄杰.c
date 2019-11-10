#include<stdio.h>
#define MAX 30
template<class Type>
int BinarySearch(Type a[],const Type& x,int n){  
int left = 0;    int right = n-1;   
while (left<=right) {
	int middle = (left+right)/2;
	if(x == a [middle])
	return middle;
	if(x > a [middle])
	left = middle+1;
	else
		right=middle-1;
}
return-1;  
}

int main(void)
{
	int a[MAX];
	int found,x,n,i,j,p;
	printf("number of data\n");
	scanf("%d",&n);
	printf("input data\n");
	for(i=0;i<n;i++)
	{
		printf("Please enter the first %d data:",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)   
	{
		p=i;
		for(j=i+1;j<n;j++)
			if(a[p]>a[j])
		p=j;
		if(p!=j)
		{
		x=a[p];
		a[p]=a[i];
		a[i]=x;
		}
	}
	printf("After sorting data is as follows:");
	for(i=0;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Input to find the number\n");
	scanf("%d",&x);
	int left=0,right=n;
	found=BinarySearch(a,x,n);
	if(found==-1)
	{
		printf("Not found\n");
	}
	else
	{
		printf("To find the number in the first %d",found+1);
	}


}
