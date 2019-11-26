#include<iostream>
using namespace std;
#define MAXSIZE 100

void MatrixChain(int *p,int n,int**m,int **s){
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

int main(){
    int p[MAXSIZE];
    int l;
    cin>>l;
    for(int i=0;i<=l;i++){
    	cin>>p[i];
	}

	int **m=new int*[MAXSIZE];
	for(int i=0;i<MAXSIZE;i++)
	 m[i]=new int[MAXSIZE];
	int **s=new int*[MAXSIZE];
	for(int i=0;i<MAXSIZE;i++)
	 s[i]=new int[MAXSIZE];
	
	MatrixChain(p,l,m,s);
	
	for(int i=1;i<l;i++){
		for(int j=1;j<l;j++)
		 cout<<m[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	
	for(int i=1;i<l;i++){
		for(int j=1;j<l;j++)
		 cout<<s[i][j]<<"\t";
		cout<<endl;
	}
	
	return 0;
}

