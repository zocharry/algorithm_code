#include <stdio.h>
#include <math.h>
#include <iostream> 
using namespace std; 

int BinarySearch(int a[], const int x, int n){
    int left = 0; int right = n-1;
    while (left <= right){
        int middle = (right+left)/2;
        if(x== a[middle])
            return middle;
        if (x > a[middle])
            left = middle+1;
        else 
            right = middle-1;
    }
    return -1;
}

void SortShuzhu(int a[]){
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = i; j < 8; j++)
        {
            int temp=0;
            if (a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    
} 

int main()
{
    int a[8];
    int x;
    int n;
    int t;
    cout<<"input 8 num a"<<endl;
    for (int i = 0; i < 8; i++)
    {
        cout<<"num"<<i<<endl;
        cin>>a[i];
    }
    SortShuzhu(a);
    for (int i = 0; i < 8; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"input you want found the num"<<endl;
    cin>>x;
    cout<<"you want fount"<<x<<endl;

    t=BinarySearch(a,x,8);
    cout<<"At position "<<t<<endl;
    
}

