#include <iostream>
using namespace std;

template<class Type>
int Partition(Type a[],int p,int r)
{
	int i=p,j=r+1;
	Type x=a[p];
	while(true)
	{
		while(a[++i]<x&&i<r);
		while(a[--j]>x);
		if(i>=j) break;
		Type temp=a[j];
		a[j]=a[i];
		a[i]=temp;
	}
	a[p]=a[j];
	a[j]=x;
	return j;
}

template<class Type>
void QuickSort(Type a[],int p,int r)   //快排使代码从小到大排序 
{
	if(p<r)
	{
	     int q=Partition(a,p,r);       
		 QuickSort(a,p,q-1);	      //排左边
		 QuickSort(a,q+1,r);          //排右边
	}
}

template<class Type>
int BinarySearch(Type a[],const Type& x,int n)     //必须排好序 
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
	    int middle=(left+right)/2;
		if(x==a[middle])	return middle;    //返回在数组中的位置 
		if(x>a[middle])   left=middle+1;
		else right=middle-1;		
	}
	return -1;	
}
 
int main()
{
	int *a,n=0,t;
	
	while(n<=0)
	{
	    cout<<"请输入至少为1的数组长度： ";
	    cin>>n;
	}
	
	
	a=new int[n+1];
	
    cout<<"下面开始为数组赋值："<<endl;	
    for(int i=0;i<n;i++)
	{ 
	    cin>>a[i];
	    if(a[i]=='\0'&&a[i]!=0) i--; //空值 
	}	
	
	QuickSort(a,0,n-1);   //从小到大，快速排序 
	
  /*  for(int i=0;i<n;i++)
	{ 
	    cout<<a[i]<<endl;   //输出数组 
	}		*/
	
	cout<<"请输入需要查找的数： ";
	cin>>t; 	
	cout<<endl; 
	if(BinarySearch(a,t,n)==-1) cout<<"找不到此数"<<endl<<endl;
	else cout<<t<<"在数组中的下标为"<<BinarySearch(a,t,n)<<endl; 
		
	delete []a;
	
	return 0;	
}
