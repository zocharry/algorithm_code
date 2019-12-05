#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
    return x<y;
}
int BinarySearch(int *a,int n,int x)
{
    int mid;
    int left=0,right=n-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(a[mid]==x)
        {
            return 1;
        }
        else if(a[mid]<x)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return 0;
}
int main()
{
    int n=8;
    int a[n];
    
    a[0]=3;
    a[1]=12;
    a[2]=5;
    a[3]=23;
    a[4]=63;
    a[5]=52;
    a[6]=43;
    a[7]=89;
    int x=43;
    sort(a,a+n,cmp);
    int answer=BinarySearch(a,n,x);
    if(answer)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}


