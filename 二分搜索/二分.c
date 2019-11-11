#include <stdio.h>
int BinarySearch(int a[], int key, int n){
	int left = 0;
	int right = n-1;
	while(left <= right){
		int middle = (left+right)/2;
		if(key == a[middle])
			return middle;
		if(key > a[middle])
			left = middle+1;
		else
			right = middle-1;
	}
	return -1;
}

int main(){
	int a[11] = {0,1,13,34,35,27,34,62,43,85,69};
	int index = BinarySearch(a,27,10);
	printf("%d\n", index);
}

