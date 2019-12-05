#include <stdio.h>
int BinarySearch(int a[], const int& x, int n)
{
    int left=0, right=n-1;
    while (left <= right)
    {
        int middle = (left+right)/2;
        if (x==a[middle])
        {
            return middle;
        }
        if (x > a[middle])
        {
            left = middle+1;
        }
        else
        {
            right = middle-1;
        }
    }
    return -1;
}
 
int main()
{
    //int a[] = {1,4,7,9,11,17};
    //printf("%d\n",BinarySearch(a,4,6));
    int i,x,a[100],n;
    printf("输入需要的数组的长度：\n");
    scanf("%d",&n); 
    printf("输入数组中的元素：\n");
    for(i=0;i<n;i++)
    { 
        scanf("%d",&a[i]);    
    } 
    printf("请输入你想查找的元素：\n");
    scanf("%d",&x);  
	printf("该元素在数组中的下标是%d\n",BinarySearch(a,x,n));
   
    return 0;
}

