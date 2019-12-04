#include <stdio.h>
int BinarySearch(int a[], const int& x, int n)
{
    int left=0, right=n-1;
    while (left <= right)
    {
        int middle = (left+right)/2;
        if (x == a[middle])
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
    int a[] = {1,2,10,20,25,30,100,200,300,1000};
    printf("a[%d]\n",BinarySearch(a,25,10));
}

