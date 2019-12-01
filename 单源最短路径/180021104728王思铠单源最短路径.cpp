#include <iostream>
using namespace std;
template<class Type>
#define NUM 100
#define maxint 1000
void Dijkstra(int n,int v,int dist[],int prev[],Type **c)
{
	bool s[maxint];
	for(int i=0;i<=n;i++)
	{
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint)
		prev[i]=0;
		else
		prev[i]=v;
	}
	dist[v]=0;
	s[v]=true;
	for(int i=1;i<n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++){
			if((!s[j]&&(dist[j]<temp)))
			{
				u=v;
				temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j]) && (c[u][j]<maxint)){
					int newdist =dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			}
		}
		
	}
	
}
int main(){
	cout<<"请输入点的输入和边的数目："<<endl;	
	int n,v,x;
	int dist[NUM];
	int prev[NUM];
	int c[NUM][NUM];
	cin>>n>>v;
	for(int i=0;i<NUM;i++){
		for(int j=0;j<NUM;j++)
		c[i][j]=maxint;
	}
	cout<<"请输入边及边的权："<<endl;
	for(int i=0;i<v;i++){
		int v0,v1,w;
		cin>>v0>>v1>>w;
		c[v0][v1]=w;
	} 
	Dijkstra(n,1,dist,prev,c);
	cout<<"请输入一个点："<<endl;
	 cin>>x;
	 cout<<"最短路径为："<<dist[x]; 
		
	   return 0;
		
		
	}

	
	
	
	

	

