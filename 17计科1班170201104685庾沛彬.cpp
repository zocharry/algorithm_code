/*
班级：17计算机科学与技术1班 
学号：170201104685
姓名：庾沛彬 

二分搜索算法 
*/

#include<iostream>
using namespace std;

int BinarySearch(int s[], int n, int key)
{
	int left = 0;
	int right = n - 1;
	
	while (left <= right)
	{
		int middle = left + ((right - left) >> 1);
		if (s[middle] > key)
		{
			right = middle - 1;
		} 
		else if (s[middle] < key)
		{
			left = middle + 1;
		}
		else
		{
			return middle;	
		}		
	}

	return -1;
}

int main()
{
	int s[5]={1,5,7,2,8};
	int x;
	cout<<"输入待查找元素：";
	cin>>x;
	int a=BinarySearch(s,5,x);
	cout<<endl<<"{1,5,7,2,8}"<<endl; 
	cout<<"查找元素"<<x<<"的下标为"<<a<<endl;
	return 0;
}
