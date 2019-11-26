#include<stdio.h> 
void matrixchain(int *p,int n,int m[][4],int s[][4]){ //求矩阵相乘的最优解 
	for(int i=1;i<=n;i++)
	    m[i][i]=0;
	for(int r=2;r<=n;r++)
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
int main(){
	int a[2][3]={{1,2,3},{3,2,1}};
    int b[3][4]={{2,3,4,6},{2,6,7,4},{7,3,2,9}};
    int c[4][2]={{2,3},{7,9},{3,4},{2,3}};
    int d[2][4];
    int e[2][2];
	int p[5]={2,3,4,2};    //2x3 3x4 4x2 的3个矩阵相乘 
	int n=3;
	int s[4][4];
	int m[4][4];
	matrixchain(p,n,m,s);       
	printf("最优的次数是:%d\n",m[1][3]);
	for(int i=1;i<=3;i++){
	    for(int j=1;j<=3;j++)
	        printf("%d ",m[i][j]);
	    printf("\n");
    }
	for(int i=0;i<2;i++){
		for(int j=0;j<4;j++){
			int sum=a[i][0]*b[0][j];
			for(int k=1;k<3;k++)
			   sum+=a[i][k]*b[k][j];
			d[i][j]=sum;
       }
	} 
	for(int i=0;i<2;i++){
		for(int j=0;j<4;j++){
			int sum=a[i][0]*b[0][j];
			for(int k=1;k<2;k++)
			   sum+=a[i][k]*b[k][j];
			e[i][j]=sum;
		}
	} 
	printf("矩阵连乘之后为：\n"); 
	for(int i=0;i<=1;i++){
	    for(int j=0;j<=1;j++)
	        printf("%d ",e[i][j]);
	    printf("\n");
    }
}
