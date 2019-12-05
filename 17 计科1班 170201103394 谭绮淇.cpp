/*
	170201103394
	TanQiqi 
	 Binary_Search 
*/

#include<iostream>
using namespace std;
int BinarySearch(int a[],const int& x,int n){		
	
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
int main(){
	int want_find=17;   
	int a[]={1,3,7,12,13,17,26};
	int number=BinarySearch(a,want_find,7);
	if(number){
		cout<<"Find it!"<<endl;
		cout<<number<<endl;	
	} 
	else
		cout<<"Can't find"<<endl;
	

	return 0;
}
