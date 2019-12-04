#include<iostream>
using namespace std;
#include<stdio.h>
template<class Type>
#define maxint 65535
void Dijkstra(int n,int v,Type dist[],int prev[],Type **c) {
	bool s[maxint];
	for(int i=1;i<+n;i++){
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint)
		prev[i]=0;
		else
		prev[i]=v;
	}
	dist[v]=0;s[v]=true;
	for(int i=1;i<n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++)
		if((!s[j])&&(dist[j]<temp)){
			u=j;
			temp=dist[j];
		}
		s[u]=true;
		for(int j=1;j<+n;j++){
			if((!s[j])&&(c[u][j]<maxint)){
				Type newdist =dist[u]+c[u][j];
				if(newdist<dist[j]){
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
	}
}

int main(){
	int n,v,u;

int q = 0;
cout <<"输入顶点数q：";
cin>>n;
int *way = new int[n + 1];
int **c = new int *[n + 1];
for (int i = 1; i <= n; i++)
{
c[i] = new int[n + 1];
}
cout <<"输入顶点的邻接矩阵：";
for (int j = 1; j <= n; j++)
{
for (int t = 1; t <= n; t++)
{
cin>>c[j][t];
}}
int *dist = new int [n];
int *prev = new int [n];
cout <<"输入出发点和到达点：";
cin>>v>>u;
Dijkstra(n, v, dist, prev, c);
cout <<"最短路径从";




	
}
