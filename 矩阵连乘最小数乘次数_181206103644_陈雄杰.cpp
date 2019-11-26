#include <stdio.h>  
#include <stdlib.h>   
#define MAX 50
#define inf 99999999
int p[MAX+1];             
int m[MAX][MAX];         
int s[MAX][MAX];           
int n;                    
 void matrix()  
{  
   
    int i,j,k;  
    for(i=0;i<n;i++)  
        m[i][i]=0;                  
                               
    for(i=2;i<=n;i++)  
        for(j=0;j<n-i+1;j++)
        {                         
            m[j][j+i-1]=inf;   
            for(k=0;k<i-1;k++)
            {                                    
                if(m[j][j+i-1]>m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i])
                {  
                    m[j][j+i-1]=m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i];  
                    s[j][j+i-1]=k;                         
                }  
            }  
        }  
}  
  
 void printmatrix(int leftindex,int rightindex)
{  
    if(leftindex==rightindex)  
        printf("A%d",leftindex);  
    else{  
        printf("(");  
        printmatrix(leftindex,leftindex+s[leftindex][rightindex]);  
        printmatrix(leftindex+s[leftindex][rightindex]+1,rightindex);  
        printf(")");  
    }  
}  
int main()  
{  
    int i;
    printf("Please enter the number of matrices multiplied by the matrix");
    scanf("%d",&n);
    printf("Please enter the rows and columns of the matrix in sequence (e.g. A*B, A=20*30, B=30*40)\n") ;
    for(i=0;i<n+1;i++)
    {
        scanf("%d",&p[i]);
    }
    matrix();  
    printf("The minimum number of times a matrix\t%d\n",m[0][n-1]);  
    printmatrix(0,n-1);  
    printf("\n");  
    return 0;  
}
