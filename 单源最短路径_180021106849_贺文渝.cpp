#include <iostream> 
#include <fstream>  
#include <string> 
using namespace std; 

#define M 1000

void Dijkstra(int n,int v,int dist[],int prev[],int c[][5])
{
	bool s[M];
	for(int i=1; i<=n; i++)
	{
		dist[i] = c[v][i];
		s[i] = false;

		if(dist[i] == M)
		{
			prev[i] = 0;//记录从源到顶点i的最短路径i的前一个顶点
		}
		else
		{
			prev[i] = v;
		}
	}

	dist[v] = 0;
	s[v] = true;

	for(int i=1; i<n; i++)
	{
		int temp = M;
		int u = v;//上一顶点

		for(int j=1; j<=n; j++)
		{
			if((!s[j]) && (dist[j]<temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;

		for(int j=1; j<=n; j++)
		{
			if((!s[j]) && (c[u][j]<M))
			{
				int newdist = dist[u] + c[u][j];
				if(newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}


void printTrace(int prev[],int n)
{
	for(int i=2;i<=n;i++)
	{
		printf("%d",i);
		int t=prev[i];
		while(t!=1)
		{
			printf("<<<<<<%d",t);
			t=prev[t];
		}
		printf("<<<<<1\n");
	}
}


int main(){
	int dist[5];
	int prev[5];
	int v = 1;
	int n = 5;
	int c[5][5]={	
				{M,20,M,M,M,},
			    {M,0,10,M,30},
			 	{M,M,0,50,M},
			 	{M,M,M,0,M},
				{M,M,M,20,0},
				
			};
	Dijkstra(n,v,dist,prev,c);	
	printTrace(prev,n);
	
}

