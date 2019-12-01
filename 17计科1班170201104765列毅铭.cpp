#include <iostream>

using namespace std;

template<class Type>

int BinarySearch(Type a[],const Type &x,int n){
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])return middle;
		if(x>a[middle])left=middle+1;
		else right=middle-1;
	}
	return -1;
}

int main(){
	int a[10];
	int length;
	
	do{
		cout<<"请输入数组长度：length=";cin>>length; 
		if(length<0)cout<<"input error!please try again!"<<endl;
		else break;
	}while(1);
	
	int temp;
	bool status;
	do{
		cout<<"请输入长度为"<<length<<"已排序的数组内容"<<endl;
		for(int i=0;i<length;i++){
			cout<<"a["<<i<<"]=";cin>>a[i];
			if(i==0)temp=a[i];
			else if(a[i]>=temp)temp=a[i];
			else{
				cout<<"a["<<i<<"]"<<"input error, please try again";
				continue;
			}
			if(i==length-1)status=true;
		}
		if(status)break;
	}while(1);
	
	for(int i=0;i<length;i++){
		cout<<a[i]<<"\t";
		if(i==length-1)cout<<endl;
	}
	
	int num,result;
	do{
		cout<<"请输入要查找的数字";cin>>num;
		result=BinarySearch(a,num,length);
		if(result==-1){
			cout<<"input"<<num<<"does not exist!"<<endl;
			break;
		}
		else{
			cout<<"在第["<<result<<"]位"<<endl;
		}
		 
	}while(1);
	
	return 0;
}
