#include<cstdio>
#include<iostream>

using namespace std;

int binary_research(int arr[], const int& n, int element)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid]>element)
		{
			right = mid - 1;
		}
		else if (arr[mid]<element)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int array[] = { 11, 12 , 13,14,15,16,17,18,19,20 };
	int n = sizeof(array) / sizeof(array[0]);//利用求数组长度,-1后为右下标
	//int left = 0;//定义右下标并初始化为0
	int element = 0;//定义查找的元素并初始化为0
	printf("请输入要查找的元素>");
	cin >> element;
	int location = binary_research(array, n, element);
	if (location >= 0)
		cout << "The element's location is " << location << endl;
	else
		cout << "Don't exit this element." << endl;
	system("pause");
	return 0;
}







