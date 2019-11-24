#include<stdio.h>
#include<iostream> 
#define N 100
void MatrixChain(int p[], int m[N+1][N+1],int s[N+1][N+1]) {
	int n=N;
	for(int i=1;i<=n;i++)
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
}

void Traceback(int i,int j,int **s){
	if(i==j){
		printf("A%d",i);
	}
	else
	{
		printf("(");
		Traceback(i,s[i][j],s);
		Traceback(s[i][j]+1,j,s);
		printf(")");
	}


}
int main() {
	int n;
	int q[2*N];
	int p[N+1],flag=1;
	int m[N+1][N+1];
	int s[N+1][N+1];
	printf("输入矩阵的个数: ");
	scanf("%d",&n);
	for(int i=0;i<=2*n-1;i++){
		if(i%2==0){
			printf("--------\n");
			printf("输出A%d的行:",(i/2)+1);
		}
		else
		{
			printf("*******列:");
		}
		scanf("%d",&q[i]);
	}
	for(int i=1;i<=2*n-2;i++){
		if(i%2!=0&&q[i]!=q[i+1]){
			flag=0;
			break;
		}
	}
	for(int j=1;j<=n-1;j++){
		p[j]=q[2*j];
	}
	if(flag!=0){
		p[0]=q[0];
		p[n]=q[2*n-1];
		MatrixChain(p,m,s);
		printf("\n");
		printf("最少数乘次数为%d\n",m[1][n]);
	}
	else
	{
		printf("这%d个矩阵不能连乘!\n",n);
	}
	return 0;
}
