#include<iostream>
using namespace std;
template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
	int left=0;
	int right=n;
	int i;
	while(left<=right&&i==0)
	{
		int middle=(left+right)/2;
		if(x==a[middle])
		{	i=middle;return i;
			}
		else if(x>a[middle])
			{left=middle+1;
			}
		else
		{right=middle-1;
		}
			
	}
	return -1;
	
} 
int main()
{
	char k[1024],y;
	int n=0;
	cout<<"how many numbers will you input?  "<<endl;
	cin>>n;
	cout<<"please input "<<n<<"characters from small to large.  "<<endl;
	for(int i=0;i<n;i++)
		cin>>k[i];
	cout<<"which characters you wanna search?"<<endl;
	cin>>y; 
	int p=BinarySearch(k,y,n);
	cout<<"the subscript of "<<y<<"is "<<p;
}




