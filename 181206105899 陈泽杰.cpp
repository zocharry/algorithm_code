#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;

#define maxint 255

template<typename T>

void Dijkstra(int n,int v,T dist[],int prev[],T **c) {
	bool s[maxint];

	for(int i=0;i<n; i++) {
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i] == maxint)
			prev[i] = -99;
		else
			prev[i]= v;
	}

	dist[v]=0; s[v]=true;
	
	for(int i=0;i<n;i++){
		int temp = maxint;
		int u=v;

		for(int j=0;j<n;j++) {
			if ((!s[j])&&(dist[j]<temp)){
				u=j;
				temp =dist[j];
			}
		}

		s[u] = true;

		for (int j=0;j<n;j++){
			if ((!s[j])&&c[u][j]<maxint){
				T newdist = dist[u]+c[u][j];
				if (newdist < dist [j]){
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
	}
}

#define N 5

int main() {
	int c[N][N]={
		{maxint,100,10,maxint},
		{maxint,maxint,maxint,maxint},
		{maxint,maxint,maxint,10},
		{maxint,10,maxint,maxint}},
		dist[N]={},prev[N]={},n=N,v=0;
	
	int *c1[n];

	for(int i=0;i<n;++i) {
		c1[i]=c[i];
	}
	
	Dijkstra(n,v,dist,prev,c1);

	for (int i=0;i<n;++i) {
		cout<<prev[i]<<(i==n-1?"\n":" ");
	}

	return 0;
}
