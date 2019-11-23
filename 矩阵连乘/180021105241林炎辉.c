#include <stdio.h>
#define N 20 
void MatrixChain(int p[N],int n,int m[N][N],int s[N][N]){ 
  int i,j,t,k;   
  int r;              
  for(i=1;i<=n;i++){ 
    m[i][i]=0;         //填对角线 
  }   
  //矩阵个数从两个开始一次递增  
  for(r=2;r<=n;r++){            //r是段长              
    for(i=1;i<=n-r+1;i++){      //i是段起点       
      j=i+r-1;                  //j是段终点     
      m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];  //i处分裂 
      s[i][j]=i; //初始化 
      for(k=i+1;k<j;k++){ //在K处分裂，遍历各种K的情况 
        int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
        if(t<m[i][j]){ //如果当前方案更好（少），则刷新 
          m[i][j]=t; //m[i][j]记录 
          s[i][j]=k; 
        } 
      } 
    } 
  }  
} 
  
int main(void){ 
  int n,n1,m1,i,j=2; //n为矩阵个数，n1为矩阵行数，n2为矩阵列数 
  int p[N]={0};          //存储矩阵的行和列数组  
  int m[N][N]={0};        //存储矩阵与矩阵相乘的最小次数 
  int s[N][N]={0};        //存储矩阵与矩阵相乘断开的位置  
  printf("请输入矩阵个数为:\n"); 
  scanf("%d",&n); 
  for(i=1;i<=n;i++){ 
    printf("请输入第%d个矩阵的行和列(格式为：n1*m1 ):",i); 
    scanf("%d*%d",&n1,&m1); 
    if(i==1){ 
      p[0]=n1; 
      p[1]=m1; 
    } 
    else{ 
      p[j++]=m1; 
    } 
  } 
  printf("\n相乘矩阵的行和列为:\n"); 
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
  printf("矩阵的最小相乘次数为:%d\n",m[1][n]); 
  return 0; 
} 
