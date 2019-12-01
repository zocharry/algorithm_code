#include<iostream>
using namespace std;
int search(int *a,int m,int c)
{
  int low=0;
  int high=m-1;
  while(low<=high)
  {
	  int mid=(low+high)/2;
	  if(a[mid]==c)
          return mid;
	  else
		  if(c>a[mid])
			  low=mid+1;
		  else
			  high=mid-1;
  }
  return -1;//查找失败 
}
int main()
{
    int a[16]={2,5,7,12,14,15,17,21,24,26,32,35,56,66,76,78};
	int c;
	cout<<"请输入给定的整数c"<<endl;
	cin>>c;
	int temp=search(a,16,c);
	if(temp==-1)
		cout<<"您要找的数字不存在"<<endl;
	else
        cout<<"您要找的数字对应数组的第"<<(temp+1)<<"个元素"<<endl;
	return 0;
}

