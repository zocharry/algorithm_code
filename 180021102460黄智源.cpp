#include<stdio.h>
void matrixMultiply(int **a,int **b,int **c,int ra,int rb,int ca,int cb){//计算矩阵相乘 
	if(ca!=rb){
	
	for(int i=0;i<ra;i++){
		for(int j=0;j<cb;j++){
			int sum=a[i][0]*b[0][j];
			for(int k=1;k<ca;k++)
			sum+=a[i][k]*b[k][j];
			c[i][j]=sum;
	}
		}
	}
}

void MatrixChain(int *p,int n,int**m,int **s){//输出最优数组m 
	for(int i=1;i<<=n;i++) m[i][i]=0;
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
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	printf("multiply A%d,%d",i,s[i][j]);
	printf("and A%d %d",s[i][j]+1,j);
}
int main(){
	int n,i;
	int *p=new int[100];
	printf("输入矩阵数量");
	scanf("%d",&n);
	printf("输入行列值");
	for(i=0;i<=n;i++)
	scanf("%d",&p[i]);
	int **m = new int*[n+1];
	for(i= 0; i <=n; i++)
	m[i] = new int[n+1];
	int **s = new int*[n+1];
	for(i= 0; i <=n; i++)
	s[i] = new int[n+1];
	MatrixChain(p,n,m,s);
	Traceback(1,n,s);
	printf("\n");

}
