#include <iostream> 
#include<stdlib.h>      
using namespace std;   
	  
template<class Type>  
int BinarySearch(Type a[],const Type& x,int n);  
	  
int main()  
	{  
	    int x ;  
	 
	    int a[100];  
	    for(int i=0; i<100; i++)  
	    {  
	        a[i]=i+1;  
	        cout<<a[i]<<"  ";  
	    } 
	    cout<<endl;
	    cout<<"请输入要查找的数字(1~100)" <<endl;
	    cin>>x; 
	  
	    cout<<"二分搜索查找"<<x<<"的位置下标为:";  
	    cout<<BinarySearch(a,x,100)<<endl;  
		return 0;  
	}  
	  
template<class Type>  
	int BinarySearch(Type a[],const Type& x,int n)  
	{  	
	    int left = 0;  
	    int right = n-1;  
	    while(left<=right)  
	    {  
	        int mid = (left + right)/2;  
	        if(x == a[mid])  
	        {  
	            return mid;  
	        }  
	        if(x>a[mid])  
            {  
	            left = mid + 1;  
	        }  
            else  
	        {  
	            right = mid - 1;  
	        }  
       }  
	  
    return -1;  
   }  

