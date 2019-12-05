//二分搜索技术 
#include <iostream>
using namespace std; 

template<class Type>
int BinarySearch(Type a[], const Type& x, int n){
	int left=0;
	int right=n-1;
	while (left <= right){
		int middle = (left+right)/2;
		if (x == a[middle])
			return middle;
		if (x > a[middle])
			left = middle+1;
		else
			right = middle-1;
	}
	return -1;
} 

int main(){
	char m='g';
	char y[4]={'a','b','g','w'};
	int p=BinarySearch(y,m,4);
	cout<<p;
}
