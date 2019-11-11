#include <stdio.h>
int BinarySearch(int x,int a[],int n)
{
    int left,right,middle,count=0,count1=0;
    left=0;
    right=n-1;
    while(left<right)    //査找范围不为0时执行循环体语句
    {
        count++;    //count记录査找次数
        middle=(left+right)/2;    
        if(x<a[middle])   
            right=middle-1;   
        else if(x>a[middle])
            left=middle+1;
        else if(x==a[middle])    //当key等于中间值时，证明查找成功
        {
            printf("find it!\n search %d times !a[%d]=%d",count,middle,x);    //输出査找次数及所査找元素在数组中的位置
            count1++;    //count1记录查找成功次数
            break;
        }
    }
    if(count1==0)    //判断是否查找失敗
        printf("search default!");    //査找失敗输出no found
    return 0;
}
int main()
{
    int i,x,a[100],n;
    printf("please input the array.length:\n");
    scanf("%d",&n);    //输入数组元素个数
    printf("please input array element:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);    //输入有序数列到数组a中
    printf("please input you want to search the element:\n");
    scanf("%d",&x);    //输入要^找的关键字
    BinarySearch(x,a,n);    //调用自定义函数
    printf("\n");
    return 0;
}
