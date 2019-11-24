#include<iostream>
using namespace std;

int MatrixChain(int *p,int n,int **m,int **s){
	int len;
	cin>>len;
	for (int i=1;i<=n;i++)
	m[i][i]=0;
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
	return m[1][len-1];
} 


void Traceback(int i,int j,int **s){
	if(i==j)
	return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}

int main(){
	int len;
	cout<<"please enter len:";
	cin>>len;
	int *p=new int[100];
	cout<<"please enter r/c in it:"<<endl;
    for (int i = 0; i <len; ++i)
    {
        cin >> p[i];
    }
	int **s=new int *[len];
	int **m=new int *[len];
	for(int i=0;i<len;i++){
		s[i]=new int[len];
		m[i]=new int[len];
	} 
	cout<<"矩阵连乘最少数乘次数:"<<MatrixChain(p,len-1,m,s)<<endl; 
	
	cout<<"矩阵最优计算次数为:"<<endl;
	Traceback(1,len-1,s);
	return 0;
	
	
} 
