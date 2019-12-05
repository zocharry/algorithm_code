//�������� 
#include<iostream>
using namespace std;

int BinarySearch(int a[], int x, int n) //��a[0]~a[n-1]������x 
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		
		for (int i = 0; i < n; i++) 
		{
				cout<<a[i];
				if (i == middle) {
					cout<<"#";
				}
				cout<<" ";
		}
		cout<<endl;
		if(x==a[middle])
			return middle;
		if(x>=a[middle])
		else
			right=middle-1;
	return -1;  //δ�ҵ�x 
}

int main()
{
	int x=9;
	int array[]={1,3,4,5,6,7,8,9,19,50,61,80};
	int i=BinarySearch(array,x,12);
	cout<<"x="<<x<<"�ڴ�0���"<<i<<"λ";
	if(i<0)
	{
		cout<<"δ�ҵ�x"; 
	}
}
