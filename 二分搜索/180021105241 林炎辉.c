#include <stdio.h>
#include <iostream>
using namespace std;
int binarySearch(int a[],const int& x,int n)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(x == a[middle])
        {
            return middle;
        }
        if(x > a[middle])
        {
            left=middle+1;
        }
        else
            right=middle-1; 
    }
    return -1;
}
int main()
{
    int a[]={1,2,3,4,9,11,14,16,17,20};
    int x = 9;
    int n = sizeof(a)/sizeof(a[0]);
    int index =binarySearch(a,x,n);
    cout<<index<<endl;
    return 0;
}
