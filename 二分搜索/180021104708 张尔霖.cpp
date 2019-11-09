#include <string>
#include <iostream>
using namespace std;

#define Max_size 127

template<class Type>
int BinarySearch(Type a[], const Type& x, int n)
{
	int left = 0;
	int right = n-1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (x == a[middle])
			return middle;
		if (x >= a[middle])
			left = middle + 1;
		else 
			right = middle - 1;
	}
	return -1;
}
 int main()
{	
	int a[Max_size], x, n, y;
	cout << "please enter the size\n";
	cin >> n;
	for (int i=0; i < (n-1); i++) {
		cin >> a[i];
	}
	cout << "please enter what you find\n";
	cin >> x;
	y = BinarySearch(a, x, n);
	cout << "the seat is " <<y;
	
}

