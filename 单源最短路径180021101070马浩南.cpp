#include<iostream>

using namespace std;

const int inf = 999; 

void Dijkstra(int n,int source,int dist[],int prev[],int c[6][6])
{
	bool s[inf];//用于表示点是否在s集合里 
	for(int i=1; i<=n; i++)
	{
		dist[i] = c[source][i];
		s[i] = false;//初始化的时候，除了source外所有的点都不在 s集合 
		if(dist[i] == inf) prev[i] = 0;
		else prev[i] = source;//如果相邻，前驱点是源点 
	} 
	dist[source] = 0;
	s[source] = true;
	
	for(int i=2; i<=n; i++)//没有用到i的值，只是控制循环次数,表示要找n-1个点 
	{
		int minDist = inf;
		int u = source;//u记录下距离source最近的点
		
		for(int j=1; j<=n; j++)	//从v-s集合中找点 
		{
			//j点不在s集合中，且到source的距离小于上一个点到source的距离，就用u记录下该点 
			if(!s[j] && dist[j]<minDist)
			{
				u = j;
				minDist = dist[u];
			}
		}
		
		s[u] = true;//将u点加入s集合
		
		for(int j=1; j<=n; j++)//当s集合加入新点的时候需要更新dist[]和prev[] 
		{
			if(!s[j] && c[u][j]<inf)//j点不在s集合中，且 新点与 j点相邻 
			{
				int newDist = dist[u] + c[u][j];//新点到source的距离 + 新点到 j点的距离
				if( newDist < dist[j] ) 
				{
				    dist[j] = newDist;
					prev[j] = u;//新点成了j的前驱点，表示此时从source到j点经过u距离最短 
				}
			}
		} 
	} 
}

int main()
{
	/*
	n个点
	dist[i]表示从source点到 i点的最短距离
	k=previous[i]表示经过 k点到达 i点才是最短路径 
	c[][]是临接矩阵 
	*/ 
int c[6][6]={	
				{inf,inf,inf,inf,inf,inf},
			    {inf,0,10,inf,30,100},
			 	{inf,inf,0,50,inf,inf},
			 	{inf,inf,inf,0,inf,10},
				{inf,inf,inf,20,0,60},
				{inf,inf,inf,inf,inf,0}
			};
	int dist[6];
	int prev[6];
	int source = 1;
	int n = 5;
	Dijkstra(n,source,dist,prev,c);	
	cout<<"从源点到各点的最短路径是(距离为0表示源点):";
	for(int i=1; i<=n; i++)
	cout<<dist[i]<<" ";
	cout<<endl;
	cout<<"下面输出从源点到各点的反向路径"<<endl; 
	for(int i=1; i<=n; i++)
	{
		if(i != source) 
		{
			int j = i;
			cout<<"从源点到"<<j<<"点的最短路径为:"<<endl;
			int k = j;
			while(k != source)
			{
				if( j!=source )
					cout<<j<<"  <-  ";
				else 	
					cout<<j;
				k = j;
				j = prev[j];
			}
			cout<<endl;
		}
	}
	return 0;
}

