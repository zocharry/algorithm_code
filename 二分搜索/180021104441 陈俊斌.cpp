#include <iostream>
using namespace std;
template<class Type>

int BinarySearch(Type a[],const Type& x,int n){
	int left = 0;
	int right = n - 1;
	while(left<=right){
		int middle = (left+right)/2;
		if(x==a[middle])
			return middle;
		if(x>a[middle])
			left = middle+1;
		else
			right = middle-1;		
	}
	return -1;
} 

int main(){
	int x,n,a[1000];
	cin >> x >> n;
	for(int i=0; i<x; i++) cin >> a[i];
	int ans = BinarySearch(a, x, n);
	cout << ans << endl;
	return 0;
}
