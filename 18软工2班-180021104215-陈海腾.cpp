#include<stdio.h>
#include<stdlib.h>

#define num 101
int a[num]={0};

void init()
{
    for (int i=0; i!=num;i++)
        a[i]=i;
}
int BinarySearch(int low,int high,int target)
{
    printf("target is %d\n",target);
    while (true)
    {
        int mid=(low+high)/2;
        printf("low=%2d\t high=%2d\t mid=%2d\n",a[low],a[high],a[mid]);
        if (target ==a[mid])
            return mid;
        if (low == high)
            return -1;
        if (a[mid] > target)
            high = mid - 1;
        else
            low = mid + 1; 
	}
}

int main()
{
    init();
    int n;
    printf("ÊäÈë0~100µÄÊý:\n"); 
    scanf("%d",&n);
    int id=BinarySearch(0,num- 1,n);
    if (id>0)
        printf("find it\n");
    else
        printf("not find\n");
    return 0;
}

