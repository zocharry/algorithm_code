#include<stdio.h>
#include<iostream>
using namespace std; 
#define N 20
void MatrixChain(int *p, int n, int m[][N], int s[][N]){
	for (int i=1; i<=n; i++)
		m[i][i]=0;
	for (int r=2; r<=n; r++){
		for (int i=1; i<=n-r+1; i++){
			int j=i+r-1;
			m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for (int k=i+1; k<j; k++){
				int t = m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
				if (t<m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}	
}

void TrackBack(int i,int j, int s[][N])
{
    if(i==j) return;
    TrackBack(i,s[i][j],s);
    TrackBack(s[i][j]+1,j,s);
    cout << "Multiply A" <<i<< ", " << s[i][j];
    cout << " and A" << (s[i][j]+1) << ", " <<j<<endl;
}


int main(){//д╛хо 
	int n=3,i,j;
   int p[N]={10,100,5,50};
   int s[N][N]={0};
   int m[N][N]={0};
   MatrixChain(p,n,m,s);
   TrackBack(1,n,s);
   for(i=1;i<=n;i++){ 
    for(j=1;j<=n;j++){ 
      printf("%d  ",m[i][j]); 
    } 
    printf("\n"); 
  } 
}
