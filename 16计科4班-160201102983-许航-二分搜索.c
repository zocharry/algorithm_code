// C语言实现的递归二分搜索算法
#include <stdio.h> 

// 递归二分搜索算法. 返回x在数组中的位置，否则返回-1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 

		//若搜索的元素本身就在中间
		if (arr[mid] == x) 
			return mid; 

		//若搜索的元素小于中位数，则只可能在左边部分
		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 

		//若搜索的元素大于中位数，则只可能在右边部分
		return binarySearch(arr, mid + 1, r, x); 
	} 

	// 若搜索的元素不在数组中 
	return -1; 
} 

int main(void) 
{ 
	int arr[] = { 2, 3, 4, 10, 40 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int x = 10; 
	int result = binarySearch(arr, 0, n - 1, x); 
	(result == -1) ? printf("元素不在数组中") 
				: printf("元素在数组的第%d位", 
							result); 
	return 0; 
}