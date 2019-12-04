#include <iostream>
using namespace std;
template<class Type>
int BinarySearch(Type a[],const Type& x,int n){
	int left=0;    int right=n-1;
    while(left<=right){
    	int middle=(left+right)/2;
    	if(x==a[middle])
    	    return middle;
    	
    	if(x>a[middle])
    		left=middle+1;
    		
    	else
    		right=middle-1;
    	
    }
    return-1;
}
main()
{
	char a[6];
	cout<<"请输入六个已经排好序的字符："<<endl; 
	for(int i=0;i<6;i++){
		cin>>a[i];
	} 
	char b;
	cout<<"请输入要找的字符："<<endl; 
	cin>>b;
	int p=BinarySearch(a,b,6);
	cout<<"位于："<<endl;
	cout<<p;
	
}
