#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N=1010,inf=0x3f3f3f3f;
int n,start; 
int map[N][N],dis[N],pre[N];
bool vis[N];
struct node{
	int index,dis,pre;
	friend bool operator<(node a,node b)
	{
		return a.dis>b.dis;
	}
};

void dijkstra() 
{
	dis[start]=0;
	priority_queue<node>q;
	q.push(node{start,dis[start],start});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int k=t.index;
		if(!vis[k])
		{
			vis[k]=1;
			pre[k]=t.pre;
			for(int j=1;j<=n;++j)
				if(dis[j]>dis[k]+map[k][j])
				{
					dis[j]=dis[k]+map[k][j];
					q.push(node{j,dis[j],k});
				}
		} 
	}
}
void find(int x)
{
	if(x!=start)
	{
		find(pre[x]);
		cout<<"->";
	}
	cout<<x;
}
int main()
{
	int m,x,y,v;
	memset(map,0x3f,sizeof map);
	memset(dis,0x3f,sizeof dis); 
	cout<<"请输入有几个点，几条边"<<endl;
	cin>>n>>m;
	cout<<"请分别输入每条边连通的两个点的序号，以及边的权重"<<endl;
	for(int i=0;i<m;++i)
	{
		cout<<"第"<<i+1<<"条边"<<endl; 
		cin>>x>>y>>v;
		if(v<map[x][y]) 
		{
			map[x][y]=v;
			map[y][x]=v;
		}
	}
	cout<<"请输入起点为第几个点：";
	cin>>start; 
	dijkstra(); 
	for(int i=1;i<=n;++i)
		if(dis[i]!=inf)
		{
			find(i); 
			cout<<"，起点到"<<i<<"号点的最短距离："<<dis[i]<<endl; 
		} 
		else cout<<"起点与"<<i<<"号点不连通"<<endl; 
	return 0; 
}
