 
	#include <iostream> 
	#include<stdlib.h>      
	using namespace std;   
	  
	template<class Type>  
	int BinarySearch(Type a[],const Type& x,int n);  
	  
	int main()  
	{  
	    int x;  
	    int a[20];
		cout<<"输入一个20以内的数：";
		cin>>x;  
	    for(int i=0; i<20; i++)  
	    {  
	        a[i] = i + 1;  
	    }  
	    int n=BinarySearch(a,x,20);
	    cout<<endl;
	    cout<<"二分搜索查找 "<<x<<" 的位置下标是： "<<n;
		cout<<endl;   
	    system("pause");
		return 0;  
	}  
	  
	template<class Type>  
	int BinarySearch(Type a[],const Type& x,int n)  
	{  
	    int left = 0;  
	    int right = n-1;  
	    while(left<=right)  
	    {  
	    	cout<<"left="<<left<<"\t"<<"right="<<right;
	        int mid = (left + right)/2; 
			cout<<"\t"<<"mid="<<mid; 
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
			cout<<endl;  
       }  
	  
    return -1;  
   }  

