#include <iostream>
#include <string.h>
using namespace std;

template<class Type>

int BinarySearch(Type a[],const Type& x,int n)
{
	int left = 0; 
	int right = n-1;
	while (left <= right)
	{
		int middle = (left+right)/2;
		if (x == a[middle])
		   return middle;
		if (x > a[middle])
		   left = middle+1;
		else
		   right = middle-1;
	}
	return -1;
} 

main()
{
	char m = 'f';
	int n = 5;
	char y[]={'a','e','f','h','i'};
	int p = BinarySearch(y,m,n);
	cout<<p<<endl;

}
