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
    int a[] = {1,2,3,4,5,6,7,8} ;
    printf("%d\n",BinarySearch(a,5,8));
    return 0;
}
