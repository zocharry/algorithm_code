#include <stdio.h> 
template<class Type>
int BinarySearch(Type a[], const Type& x, int n){
	int left = 0;   int right = n-1;
	while (left <= right){
		int middle =(left+right)/2;
		if(x == a[middle])
		return middle;
		if(x > a[middle])
			left = middle+1;
		else
			right = middle-1;
	}
	return-1;
}
int main()
{
    int a[] = {1,3,5,7,11,14};
    printf("%d\n",BinarySearch5(a,7,6));
}
