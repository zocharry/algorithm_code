//2.3 二分搜索算法
#include<iostream>

using namespace std;

template<class Type>
/** 
* 二分搜索
* 
*@param a[] 查找的集合 
*@param x 目标元素
*@param n 集合元素个数
*@return 目标元素的下标(未找到则为-1) 
*/ 
int BinarySearch(Type a[], const Type& x, int n)
{
	int left = 0;
	int right = n-1;
	
	while(left <= right)
	{
		int middle = (left+right)/2;
		
		if(x == a[middle])
			return middle;
		else if(x > a[middle])
			left = middle+1;
		else
			right = middle-1;
	}
	return -1;
}
 
int main()
{
	int a[10]={1,3,6,8,12,16,20,24,26,31};
	//int target = 5;
	int target = 8;
	int res = BinarySearch(a, target, 10);
	
	if(res == -1)
		cout<<"未找到"<<endl;              
	else
		cout<<"目标元素的下标为："<<(res+1)<<endl;
		
	return 0;
	
}
