//二分查找
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int nums[100];
	int target;
	int res = -1;

	cout << "请输入该有序数组的元素个数:";
	cin >> n;
	cout << "请输入该有序数组各元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	cout << "请输入需要查找的元素:";
	cin >> target;

	int l = 0;
	int r = n-1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (target > nums[mid])
		{
			l = mid + 1;
		}
		if (target < nums[mid])
		{
			r = mid - 1;
		}
		if (target == nums[mid])
		{
			res = mid;
			break;
		}
	}
	if (res != -1)
	{
		cout << "在第" << res << "号" << endl;
	}
	else
	{
		cout << "找不到该元素" << endl;
	}
	return 0;
}