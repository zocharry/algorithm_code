//Matrix multiply
#include <iostream>
using namespace std;
void MatrixChain(int p[],int n,int m[][15],int s[][15])
{//p is Matrix multiply, n is Number of matrices,
// m is Optimal solution from i to j,
// s is Where to split the optimal solution from i to j
	for(int i=1;i<=n;i++)
		m[i][i]=0;//Diagonal Fill 0 
	for(int r=2;r<=n;r++)
	{//r is segment length
		for(int i=1;i<=n-r+1;i++)
		{//i is start and j is end
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;//Initixalization
			for(int k=i+1;k<j;k++)
			{//k is different fracture positions from i to j
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])//if breaks from k is better than now,save it
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
}

void Traceback(int i,int j,int s[][15])
{
	if(i==j)
		return ;
	Traceback(i,s[i][j],s);
	//Start with the last optimal fracture position
	Traceback(s[i][j]+1,j,s);
	//deeper and find the first optimal fracture position
	cout<<"Multiply A"<<i<<", "<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<<", "<<j<<endl;
} 
int main()
{
	int m[15][15]={0};
	int s[15][15]={0};
	int p[20]={0};
	int n;
	cout<<"Please enter the number of matrices:"<<endl;
	while(cin>>n)
	{
		cout<<"Enter the length and width of the "<<n<<"-matrix in order:"<<endl;
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			if(i==1)//Judge and save the rows and columns of the matrix
			{
				p[0]=a;
				p[1]=b;
			}
			else if(a==p[i-1])
				p[i]=b;
			else if(b==p[i-1])
				p[i]=a;
			else
			{
				cout<<"The matrix cannot be multiplied by the previous matrix."<<endl;
				break;
			}
		}
		MatrixChain(p,n,m,s);
		cout<<"The minimum multiplier is "<<m[1][n]<<"."<<endl;
		Traceback(1,n,s);
		cout<<endl; 
		cout<<"Please enter the number of matrices:"<<endl;
	}
	return 0;
} 
