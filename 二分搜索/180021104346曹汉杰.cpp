#include<iostream>
template<class Type>
int BinarySearch(Type a[], const Type&x, int n){
 int left=0;
 int right=n-1;
 while(left<=right){
  int middle=(left+right)/2;
  if(x==a[middle])
   return middle;
  if(x>a[middle])
   left=middle+1;
   else
    right=middle-1;
 } 
 return -1;
}
 //a[0]<=a[1]<=a[2]<=...<=a[n-1]to find x,Returns its number in the array when it finds x
using namespace std;
int main()
{
 char m='h';
 char y[4]={'a','b','c','d'};
 int x=BinarySearch(y,m,4);
 cout<<x;
}
