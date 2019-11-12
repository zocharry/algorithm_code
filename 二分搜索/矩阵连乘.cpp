#include<iostream>
#define N 7
using namespace std;
int MatrixChain(int *p, int n, int m[][N], int s[][N]){
	for(int i=1;i<=n;i++){     
	m[i][i]=0;
	} 
	for(int r=2;r <= n;r++){
		for(int i=1;i <= n-r+1;i++){
			int j = i+(r-1);
			m[i][j] = m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k < j;k++){
				int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
void Traceback(int i,int j, int s[][N]){
	if(i==j){
		cout<<"A"<<i;
	} 
	else
	{
	cout<<"(";
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s); 
	cout<<")";
	}
}
int main(){
	int p[N]={30,35,15,5,10,20,25};
	int m[N][N],s[N][N];
	MatrixChain(p,N-1,m,s);
	Traceback(1,6,s);
	return 0;
} 
