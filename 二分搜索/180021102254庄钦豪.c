#include<iostream>
template<class Type>
int BinarySearch(Type a[], const Type&x, int n){
	//在a[0]<=a[1]<=a[2]<=...<=a[n-1]中搜索x
	//找到x时返回其在数组中的数字
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
using namespace std;
int main()
{
	char m='h';
	char y[4]={'a','b','h','d'};
	int w;
	int p=BinarySearch(y,m,4);
	cout<<p;
}
