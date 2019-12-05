//二分搜索算法 
#include<iostream>
using namespace std;

template<class Type>
int BinarySearch(Type a[],const Type& x,int n){
	int left = 0;
	int right = n-1;
	while(left <= right){
		int middle = (left + right)/2;
		if(x == a[middle])
			return middle;
		if(x > a[middle])
			left = middle+1;
		else
			right = middle-1;
	}
	return -1;
} 

int main(){
	int num = 0,len = 20;
	//要找的数，数组大小 
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,22,33,44,55,66,77,88,99,100};
	cout << "Please input an integer:";
	cin >> num;
	int rst = BinarySearch(a,num,len);
	if(rst != -1)
		cout << "The location of the queried value is:" << rst  <<endl;
	else
		cout << "The value you entered is not one of them!" << endl;
	return 0;
}
