#include<iostream>
using namespace std;

template<class Type>

int sorting(Type a[],const Type &num,int length)
{
	int left=0;
	int right=length-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(num==a[middle])
		{
			return middle;
		}
		if(num>a[middle])
		{
			left=middle+1;
		} 
		else{
			right = middle-1;
		}
	}
	return -1;
}



int main()
{
	int length,rtn,status2;
	double a[10],b,num;
	bool status=false;	
	bool status1=false;
	while(1)
	{
		cout<<"请输入您要输入的二分搜索的数组的长度length（length>0）"<<endl;
		cout<<"length=";cin>>length; 
		if(length<=0)
		{
			cout<<"输入错误，数组长度应大于0"<<endl;
		}
		else
		{
			break;
		 } 
	}
	while(1)
	{
		
		cout<<"请输入一段排好序的"<<length<<"个数字的数组（由小到大）"<<endl;
		for(int i=0;i<length;i++)
		{
		
			cout<<"a["<<i<<"]=";cin>>a[i];
			if(i==0)
			{
				b=a[0];
			 } 
			if(a[i]>=b)
			{
				b=a[i];
			}
			else{
				cout<<"第"<<i+1<<"个输入错误，数列不为升序"<<endl;
				cout<<"请重新输入"<<endl; 
				break; 
			}
			if(i==length-1)
			{
				status=true;
			}
		}
			if(status)
			{
				break;
			}
	} 
	while(1)
	{
		cout<<"请输入要查的数字 num:";cin>>num;
		rtn=sorting(a,num,length);
		if(rtn==-1)
		{
			cout<<"该数组不存在数字"<<num;
		}
		cout<<"数字"<<num<<"位于数组的第"<<rtn<<"位,a["<<rtn<<"]=num="<<num<<endl;
			cout<<"继续查询请按1，退出查询请按任意键:";cin>>status2;
		if(status2!=1)
		{
			break;
		}
	 } 
	cout<<"已退出系统";
	return 0;
 } 
