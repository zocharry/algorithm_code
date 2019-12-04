#include<bits/stdc++.h>
using namespace std;
int a[1010] ;
int cmp(int a,int b)
{
	return a<b ;
}
int aaa(int t,int a[],int n)
{
	int l,r,m ,c;
	l=1 ,r=n ;
	while(l<r)
	{
		m=(l+r)/2 ;
		if(t==a[m])
		return m ;
		else if(t<a[m])
			r=m-1 ;
		else if(t>a[m])
			l=m+1 ;
	}
	return 0;
	
}
int main()
{
	int n;
	cin>>n ;
	for(int i=1;i<=n;i++)
	cin>>a[i] ;
	sort(a+1,a+n+1,cmp) ; 
	int t,p;
	cin>>t ;
	p=aaa(t,a,n) ;
	if(p)
	cout<<"在第"<< p<<"的位置"<<endl ;
	else
	cout<<"未找到"<<endl ; 
	
}
