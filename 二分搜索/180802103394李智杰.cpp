#include <Stdio.h> 
#include <iostream>
using namespace std;
#define MAXSIZE 100
template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
int left=0; 
int right=n-1;
while(left<=right){
	int middle=(left+right)/2;
	if(x==a[middle])
	return middle;
	if(x>a[right])
	left=middle+1;
	else
	right=middle-1;
}
return-1;
}

int main(){
	int a[MAXSIZE];
	int x,i,length,p;
	 cout<<"请输入数组大小"<<endl;
	cin>>length;
	cout<<"请输入数组内容"<<endl;
	for(i=0;i<length;i++){
		cin>>a[i];}
	cout<<"请输入要搜索的内容"<<endl;	
	 cin>>x;
	p=BinarySearch(a,x,length);
	if(p==-1)
        cout<<"该数不存在！"<<endl;
    else
    cout<<"数字所在的位置为第";
    cout<<p+1<<endl;
    
	
}


