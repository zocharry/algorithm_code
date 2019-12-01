#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define maxint 9999
#define N 5

using namespace std;

template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type **c){
	bool s[n+1];
	for(int i=0;i<=n;i++){
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint)
			prev[i]=0;
		else
			prev[i]=0;
	}
	dist[v]=0;s[v]=true;
	for(int i=0;i<n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j])&&(c[u][i]<maxint)){
					Type newdist=dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			}
		}
	}
} 

void Tracebake(int v,int i,int prev[]){
	if(v==i){
		cout<<i;
		return ;
	} 
	Tracebake(v,prev[i],prev);
		cout<<"->"<<i;
}

int main(){
	int v=1;
	int dist[N+1],*prev,**c;
	c = (int **)malloc(N*sizeof(int *));
    prev=(int*)calloc(sizeof(int),N);
    for (int i = 0; i < N; i++)
    {
        c[i] = (int *)malloc(N*sizeof(int));
    }
	cout<<"有向图权的矩阵为："<<endl;
	for(int i;i<N;i++){
		for(int j;j<N;j++){
			cin>>c[i][j];
		}
		cout<<endl;
	}
	Dijkstra(N,v,dist,prev,c);
	for(int j=2;j<=N;j++){
		cout<<"源点1到点"<<j<<"的最短路径长度为："<<dist[j]<<"其路径为：";
		Traceback(1,j,prev);
		cout<<endl;
	}
	return 0;
}


