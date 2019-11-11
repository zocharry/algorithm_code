#include <iostream>
#include <algorithm> 
using namespace std;
template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{//search in a[0]<=a[1]<=бн<=a[n-1]
//if found return the position else return -1
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(x==a[middle])//found and return 
			return middle;
		if(x>a[middle])//x bigger than mid and turn right
			left=middle+1;
		else//x smaller than mid and turn left
			right=middle-1;
	}
	return -1;
}
int main()
{
	int n;
	cout<<"Please enter the array length:"<<endl;
	cin>>n;
	cout<<"Please enter the array, separated by spaces:"<<endl;
	int a[100];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int x;
	cout<<"Please enter the element which you search:"<<endl;
	while(cin>>x)
	{
		int result=BinarySearch(a,x,n);
		if(result==-1)
			cout<<"No found"<<endl;
		else
			cout<<"The element is "<<result+1<<"-th"<<endl; 
		cout<<"Please enter the element which you search:"<<endl;
	} 
	return 0;
} 
