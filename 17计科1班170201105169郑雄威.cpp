#include<iostream>

using namespace std;

int BinarySearch(int *a, int x, int n){
	int left = 0;
	int right = n-1;
	while(left <= right){
		int middle = (left + right) / 2;
		if(x == a[middle])
			return middle;
		if(x > a[middle])
			left = middle + 1;
		else
			right = middle -1;
	}
	return -1;
}
int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int want_find;
	cout << ¡°please input want find¡± << endl;
	cin >> want_find;
	int x = BinarySearch(a,want_find,10);
	cout << x << endl;
	return 0; 
}
