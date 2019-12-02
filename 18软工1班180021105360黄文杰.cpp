#include <iostream>
#include <algorithm> 
using namespace std;
template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
	//在a[0]<=a[1]<=...<=a[n-1]中搜索x
	//找到x时返回其在数组中的位置，否则返回-1 
	int left=0; //第一个数 
	int right=n-1; //最后一个数 
	while(left<=right)  
	{
		int middle=(left+right)/2;
		if(x==a[middle]) 
			return middle; //找到要搜索的元素 
		if(x>a[middle]) //比中间的数大 
			left=middle+1; 
		else //比中间的数小 
			right=middle-1;
	}
	return -1;//未找到x 
}
int main()
{
	int n;
	cout<<"请输入数组长度："<<endl;
	cin>>n;
	cout<<"请输入数组（用空格隔开，数字从小到大排列）："<<endl;
	int a[100];
	//输入元素 
	for(int i=0;i<n;i++)
		cin>>a[i];
	//要搜索的元素 
	int x;
	cout<<"请输入要搜索的元素："<<endl;
	while(cin>>x)
	{
		int s=BinarySearch(a,x,n);//返回的结构赋值给s 
		if(s==-1)
			cout<<"没有找到"<<endl;
		else
			cout<<"元素是第"<<s+1<<"个"<<endl; 
		cout<<"请输入要搜索的元素："<<endl;
	} 
	return 0;
} 
