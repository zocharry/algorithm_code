#include <iostream>

using namespace std;

int BinarySearch(int a[],int x,int n)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int middle = (left + right)/2;
		if (x == a[middle])
			return middle;
		if (x > a[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
 } 
 
int main(){
	int nums[7] = {5,12,23,45,66,78,98};
	cout << BinarySearch(nums,66,7) <<endl;
	return 0;
}
