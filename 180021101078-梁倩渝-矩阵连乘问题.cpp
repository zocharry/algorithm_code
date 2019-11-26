#include <iostream>
using namespace std;
void MatrixChain(int *p,int n,int **m,int **s);
void Traceback(int i,int j,int **s);
int main()
{
	int n=4;
	int *m[n+1],*s[n+1],p[n+1]={3,5,8,4,2};
	for(int i=0;i<n+1;i++)
	{
		s[i]=new int[n+1];
		m[i]=new int[n+1];
	}
	MatrixChain(p,n,m,s);
	cout<<"矩阵的最优计算次序："<<endl; 
	Traceback(1,n,s);
	cout<<"矩阵的最少计算次数："<<m[1][n]<<endl;
	return 0;	
}
void MatrixChain(int *p,int n,int **m,int **s)
{
	for(int i=1;i<=n;i++)
	{ 
		m[i][i]=0;
	}
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
}
void Traceback(int i,int j,int **s)
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
}
