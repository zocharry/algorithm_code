#include <iostream>
using namespace std;
void MutrixChain(int p[7],int n,int m[7][7],int s[7][7]){
	for(int i=0;i<=n;i++){
		m[i][i]=0;
	}
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i+1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}			
			}
		}
	}
}
void Traceback(int i,int j,int s[7][7]){
	if(i==j){
		return;}
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}
int main(){
	
	int p[7]={30,35,15,5,10,20,25};
	int s[7][7];
	int m[7][7];
	int n=6;
	MutrixChain(p,n,m,s);
	Traceback(1,n,s);
}
