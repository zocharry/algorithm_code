#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
template<typename Type>
#define maxint 999
void Dijkstra(int n,int v,Type dist[],int prev[],Type **c) {
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
				Type newdist = dist[u]+c[u][j];
				if (newdist < dist [j]){
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
	}	
}

int main(){
	int c[5][5]={{maxint,100,10,maxint},{maxint,maxint,maxint,maxint},{maxint,maxint,maxint,10},{maxint,10,maxint,maxint}};
	int dist[5]={},prev[5]={},n=5,v=0,*c1[n];
	for(int i=0;i<n;++i) {
		c1[i]=c[i];
	}
	Dijkstra(n,v,dist,prev,c1);
	for (int i=0;i<n;++i) {
		cout<<prev[i]<<endl;
	}

	return 0;
}
