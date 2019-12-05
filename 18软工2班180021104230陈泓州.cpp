#include <iostream>
#include<string.h>
#include<stdio.h>
#define N 7
using namespace std;
int BinSearch(int *A,int target,int left,int right){
	while(left <= right){
		int mid = (left+right)/2;
		if(target < A[mid])
			right = mid - 1;
		else if(A[mid] < target)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main(){
	int nums[N],i=0,a;
	cout << "请输入7个数字，用空格隔开(回车结束输入): "; 
	while(cin >> a){
    	nums[i] = a;
		char ch = getchar(); 
    	if(ch == '\n')
    	break;
    	else{
			i++;
			continue; 
		} 
	}
	cout << "请输入要查找的数字: "; 
	cin >> a;
	cout << "查找数字为:" << a << "\t下标为(-1则查找失败):" << BinSearch(nums,a,0,6) << endl;
	return 0;
}
