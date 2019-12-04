#include <stdio.h>
#include <stdlib.h>
 
int Search(int *m, int key)
{
    
    int low = 0, mid; 
    int high = 9;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == m[mid])
            return mid; 
        else if (key < m[mid])
            high = mid - 1; 
        else
            low = mid + 1;
    }
    return -1; 
}
int main()
{
    int *m, key, i;
    int n[10] = {0};
    m = n;
    printf("请输入10个整数：\n");
    for (i = 1; i <= 10; i++)
    {
        scanf("%d", &n[i - 1]);
        printf("\n");
    }
    printf("请输入要查找的数：\n");
    scanf("%d", &key);
    i = Search(m, key);
    if (-1 == i)
        printf("数不在数组中！\n");
    else
        printf("数的数组下标为 %d \n", i);
}
