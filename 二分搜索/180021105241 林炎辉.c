#include <stdio.h>
BinarySearch(int a[], int n, int key){
    int low = 0;
    int high = n - 1;
    while(low<= high){
        int mid = (low + high)/2;
        int midVal = a[mid];
        if(midVal<key)
            low = mid + 1;
        else if(midVal>key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
int main(){
    int i,a[100],n,val, ret;//a[100]为数组， n为数组长度， val为所要查找的元素 ， ret为判断是否查找成功的参数 
    printf("请输入数组长度n=");
    scanf("%d\n",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
  }
 printf("数组元素为:");
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);
    printf("\n请输人所要查找的元素：");
    scanf("%d",&val);
    ret = BinarySearch(a,i,val);
    if(-1 == ret)
        printf("查找失败 \n");
    else
        printf ("查找成功 \n");
    return 0;
}
