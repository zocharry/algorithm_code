#include <stdio.h>
#define N 20 
void eatrixMultiply(int a[N][N],int b[N][N],int c[N][N],int ra,int ca,int rb,int cb){
	if(ca!=rb)
	   printf("矩阵不可乘");
	for(int i=0;i<ra;i++){
		for(int j=0;j<cb;j++){
			int sum=a[i][0]*b[0][j];
			for(int k=1;k<ca;k++)
			sum+=a[i][k]*b[k][j];
			c[i][j]=sum;
		}
	} 

} 
void MatrixChain(int p[N],int n,int m[N][N],int s[N][N]){ 
    for(int i=1;i<=n;i++){ 
    m[i][i]=0;         //当一个矩阵相乘时，相乘次数为 0  
  }   
  //矩阵个数从两个开始一次递增  
    for(int r=2;r<=n;r++){ 
    //从某个矩阵开始     
    for(int i=1;i<=n-r+1;i++){ 
      //到某个矩阵的结束  
    int j=i+r-1; 
      //拿到从 i 到 j 矩阵连乘的次数  
      m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j]; 
      //拿到矩阵连乘断开的位置  
      s[i][j]=i; 
      //寻找加括号不同，矩阵连乘次数的最小值，修改 m 数组，和断开的位置 s 数组  
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
void Traceback(int i,int j,int s[N][N]){
	if(i==j)
	  return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	printf("Multiply A:",i,s[i][j]);
	printf(" A:",i,s[i][j]);
}
int main(void){ 
  int n,n1,m1,i,j=2; 
  int p[N]={0};        
  int m[N][N]={0};        //存储矩阵与矩阵相乘的最小次数 
  int s[N][N]={0};        //存储矩阵与矩阵相乘断开的位置  
  printf("请输入矩阵个数:\n"); 
  scanf("%d",&n); 
  for(i=1;i<=n;i++){ 
    printf("请输入第%d个矩阵的行和列(n1*m1 格式):",i); 
    scanf("%d*%d",&n1,&m1); 
    if(i==1){ 
      p[0]=n1; 
      p[1]=m1; 
    } 
    else{ 
      p[j++]=m1; 
    } 
  } 
  printf("\n记录矩阵行和列:\n"); 
  for(i=0;i<=n;i++){ 
    printf("%d ",p[i]); 
  } 
  printf("\n"); 
  MatrixChain(p,n,m,s); 
  printf("\n矩阵相乘的最小次数矩阵为:\n"); 
  for(i=1;i<=n;i++){ 
    for(j=1;j<=n;j++){ 
      printf("%d  ",m[i][j]); 
    } 
    printf("\n"); 
  } 
  printf("\n矩阵相乘断开的位置矩阵为:\n"); 
  for(i=1;i<=n;i++){ 
    for(j=1;j<=n;j++){ 
      printf("%d ",s[i][j]); 
    } 
    printf("\n"); 
  } 
  printf("矩阵最小相乘次数为:%d\n",m[1][n]); 
  return 0; 
} 
