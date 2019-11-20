#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;
#define N 6
void MatrixChain(int *p, int n, int m[N+1][N+1], int s[N+1][N+1]){
	for(int i=1; i <= n; ++i) m[i][i] = 0;
	for(int r=2; r <= n; ++r) {
		for(int i=1; i <= n-r+1; ++i) {
			int j = i+r-1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for(int k = i+1; k<j; ++k) {
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
void Traceback(int i, int j, int s[N+1][N+1]) {
	if(i == j) return;
	Traceback(i, s[i][j], s);
	Traceback(s[i][j]+1, j, s);
	cout<<"Multiply A "<<i<<","<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<<", "<<j<<endl;
}
int main() {
  //input
	int p[]={30,35,15,5,10,20,25},m[N+1][N+1]={}, s[N+1][N+1]={};
	MatrixChain(p, N, m, s);
	for(int i=1;i<N+1;++i){
		for(int j=1;j<N+1;++j)cout<<m[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<N+1;++i){
		for(int j=1;j<N+1;++j)cout<<s[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	Traceback(1, N, s);
	return 0;
}
