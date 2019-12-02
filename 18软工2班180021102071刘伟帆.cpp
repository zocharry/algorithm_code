#include<iostream>
#define MAX_SIZE 102
using namespace std;
template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(a[middle]==x)
            return middle;
        if(x>=a[middle])
            left=middle+1;
        else
            right=middle-1;
    }
    return -1;
}
int main()
{
    int a[MAX_SIZE];
    int i,len,x,p;
    cin>>len;
    for(i=0;i<len;i++)
        cin>>a[i];
    cin>>x;
    p=BinarySearch(a,x,len);
    if(p==-1)
        cout<<"该数不存在！"<<endl;
    else
    cout<<p+1<<endl;
    return 0;
}
