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
    int a[] = {1,6,9,17,21,34,50,87,100};
    
    printf("%d\n",BinarySearch(a,6,9));
}
