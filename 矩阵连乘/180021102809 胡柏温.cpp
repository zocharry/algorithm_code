#include<stdio.h>
void MatrxChin(int *p,int n,int **m,int **s){
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
	//下面为显示 
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
		   printf("%d\t",s[i][j]);
		}
		printf("\n");
	}
	
}
int main(){
	int p[]={30,35,15,5,10,20,25};
	int n=7;
	int **m=new int *[n];
	int **s=new int *[n];
	for(int i=0;i<n;i++){
		m[i]=new int[n]();
		s[i]=new int[n]();
	} 
	MatrxChin(p,n-1,m,s);
} 
