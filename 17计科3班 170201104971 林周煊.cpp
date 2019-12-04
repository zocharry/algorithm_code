#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"输入数组的数字个数"<<endl;
	cin>>n;
	int p[n];
	cout<<"输入数组（空格隔开，无需排序）"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	int t;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-1);j++)
		{
			if(p[j]>p[j+1])
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
	cout<<"排序后的数组为："<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;
	cout<<"请输入要查找的数字"<<endl;
	int tag;
	cin>>tag;
	int left=0;
	int right=n-1;
	int middle=0;
	int end;
	int sign=0;
	while(left<right)
	{
		middle=(left+right)/2;
		if(p[middle]==tag)
		{
			end=middle;
			sign=1;
			break;
		}
		else
		if(tag>p[middle])
		{
			left=middle+1;
		}
		else
		{
			right=middle-1;
		}
	}
	if(sign==0)
	{
		cout<<"未在数组找到指定数字"<<endl;
	}
	else
	{
		cout<<"所找数字在排序数组中下标为："<<end<<endl; 
	}
	return 0;
} 





