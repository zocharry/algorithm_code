#include<iostream>

using namespace std;
int k(int a[],int x, int n){
	
	int left = 0;
	int right =n-1;
	
	while (left<=right){
		int middle = (left+right)/2;
		if(x==a[middle])
			return middle;
		if(x>a[middle])
			left = middle+1;
		else
			right= middle-1;	
	}
	return -1;
} 

int main (){
	int a[]={1,3,6,5,4,7,8,9,11,21,32,65,54,98,87,74,85,96,36,52,14,44,57,86,35,24,69,12,15,26,112,352,662,77,255} ;
	int x =0; 
	
	cout<<"请输入想要查询的数字"<<endl;
	cin>>x;
	
	if (k(a,x,35)==-1)
		cout<<"未查到该数字"<<endl;
	else
		 cout<<"已查询到位于数组"<<k(a,x,35)<<"处"<<endl;
}
