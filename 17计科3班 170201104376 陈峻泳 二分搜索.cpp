#include<iostream>
 #include<algorithm>
 using namespace std;
 bool compare(int a,int b)
 {
     return a<b;                    
 }
 template<class Type>int BinarySearch(Type a[],const Type& x, int n)
 {
     int left=0;
     int right=n-1;
     while(left<=right)
     {
         int middle=(left+right)/2;
         if(a[middle]==x) return middle;
         if(a[middle]<x) left=middle+1;
         else right=middle-1;
     }
     return -1;
 }
 int main()
 {
 	cout<<"how many numbers in the array:"; 
     int a[100];
     int n,m;
     cin>>n;
     for(int i=0; i<n; i++)
     {
         cin>>a[i];
     }
     
     sort(a,a+n,compare);
     
     for(int i=0; i<n; i++)
     {
         cout<<a[i]<<" ";
     }
     cout<<endl;
     m=BinarySearch(a,234,n);
     cout<<m<<endl;
     return 0;
 }

