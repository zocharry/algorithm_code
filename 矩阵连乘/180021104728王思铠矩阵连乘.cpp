#include<iostream>
using namespace std;
const int Max =100;
int p[Max];//矩阵维数
int m[Max][Max];//最优值，最少乘法次数
int s[Max][Max];//断开的位置
int n;//矩阵个数 
 
void MatrixChain(){ //计算最优值
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(int r=2;r<=n;r++){
        for(int i=1;i<=n-r+1;i++){
            int j=r+i-1;
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
 
void TrackBack(int i,int j){//最优方法 
    if(i==j) return;
    TrackBack(i,s[i][j]);
    TrackBack(s[i][j]+1,j);
   cout<<"A"<<i<<","<<s[i][j];
   cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl; 
}
int main(){
	cout<<"请输入要测试的矩阵个数和各个矩阵的维数："; 
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>p[i];
	}
	cout<<"连乘方法为："<<endl; 
	MatrixChain();
	TrackBack(1,n);
	cout<<"最优值为："; 
	cout<<m[1][n]<<endl;
	return 0;
}
 

