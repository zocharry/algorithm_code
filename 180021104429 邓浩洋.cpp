#include <stdio.h>
int binarySearch(int a[], const int& x, int n)
{
    int left=0, right=n-1;
    while (left <= right)
    {
        int middle = (left+right)/2;
        if (x==a[middle])
        {
        }
            return middle;
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
    int a[] = {5,9,15,23,33,45};
    printf("%d\n",binarySearch(a,6,6));     
    
}
