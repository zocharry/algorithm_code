#include<stdio.h> 
int BinarySerch(int a[],int x,int n){
	int left=0;
	int right=n-1;
	while(left<=right){
	int middle=(left + right)/2;
	if(x==a[middle])
	return middle+1;
	if(x==a[middle])
	  left=middle+1;
	else
	  right=middle-1;
    }
    return -1;
}
int main(){
	int a[3]={2,0,1};
	printf("%d",BinarySerch(a,0,3));
	return 0; 
}
