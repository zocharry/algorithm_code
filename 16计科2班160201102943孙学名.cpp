#include<iostream>
#include<stdlib.h>
using namespace std;



int BinarySearch(int arry[], int len, int value)
{

	if (arry == NULL || len <= 0)
		return -1;

	int start = 0;
	int end = len - 1;

	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (arry[mid] == value)
			return mid;
		else if (value < arry[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;

}


int BinarySearchRecursion(int arry[], int value, int start, int end)
{
	if (start > end)
		return -1;

	int mid = start + (end - start) / 2;
	if (arry[mid] == value)
		return mid;

	else if (value < arry[mid])
		return    BinarySearchRecursion(arry, value, start, mid - 1);
	else
		return    BinarySearchRecursion(arry, value, mid + 1, end);

}

int BinarySearchRecursion(int arry[], int len, int value)
{
	if (arry == NULL || len <= 0)
		return -1;
	return BinarySearchRecursion(arry, value, 0, len - 1);
}

void main()
{
	int arry[] = { 1,2,3,4,5,6,7,8 };
	int len = sizeof(arry) / sizeof(int);

	int index = BinarySearch(arry, len, 4);
	cout << "index:" << index << endl;

	int index2 = BinarySearchRecursion(arry, len, 8);
	cout << "index2:" << index2 << endl;

	system("pause");
}