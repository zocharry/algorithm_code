#include<stdio.h>
template<class Type>
int BinarySearch(Type a[],const Type& x,int n){
	int left=0;                             
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])
		printf("This number is in the %d position\n",middle+1);
		if(x>a[middle])
		left=middle+1;
		else 
		right=middle-1;
	}
	return-1;
}

int main(){
	int i,n,x;
	printf("How many elements are ordered?:");
	scanf("%d",&n); 
	printf("Please enter %d elements:",n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);	
	}
	printf("Please enter the number you are looking for:\n");
    scanf("%d",&x);
	BinarySearch(a,x,n);
	return 0;
}
