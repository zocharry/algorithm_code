#include<iostream>
using namespace std;

const int MAX = 100;
int p[MAX+1],m[MAX][MAX],s[MAX][MAX];
int n;

void MatrixChain(){
	for(int i=1;i<=n;i++){
		m[i][i]=0;
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if (t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}	
			}	
		}
		}	
	}
}
void Traceback(int i,int j){
	if(i==j)
		return;
	Traceback(i,s[i][j]);
	Traceback(s[i][j]+1,j);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<"and A"<<s[i][j]+1<<","<<j<<endl;
} 
int main(){
	cout<<"请输入矩阵的个数n:"<<endl;
	cin>>n;
	int i,j;
	cout<<"请依次输入每个矩阵的行数和最后一个矩阵的列数:"<<endl;
	for(i=0;i<=n;i++)cin>>p[i];
	MatrixChain();
	Traceback(1,n);
	cout<<m[1][n]<<endl;
	return 0;
}	
	
	 

