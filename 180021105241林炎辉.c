//Dijkstra算法解决单源最短路径问题
#include <stdio.h>
#define V 1 //设源顶点为V
#define maxint 1000

int Dijkstra(int n,int v, int dist[],int prev[],int c[][20]) 
{
	int i,j;
	int s[20];
	for(i=1;i<=n;i++)
	{
		dist[i]=c[v][i];//dist[]记录到各点的最短特殊路径  c[v][i]为邻接矩阵 
		s[i]=0;
		if(dist[i]==maxint)
		    prev[i]=0;
		else
		    prev[i]=v;   //前驱 
	}
	dist[v]=0;s[v]=1;//s[]数组，记录红点集 
	
	for(i=1;i<n;i++)//每次转化一个非红点 
	{
		int temp=maxint;
		int u=v;
		for(j=1;j<=n;j++)
		    if((!s[j])&&(dist[j]<temp))  //temp记录下最短dist 
		    {
		    	u=j;
		    	temp=dist[j];
			}
		s[u]=1;//u点成为红点 
		//更新dist[]
    for(j=1;j<=n;j++)
        if((!s[j])&&(c[u][j]<maxint))
        {
        	int newdist=dist[u]+c[u][j];
        	if(newdist<dist[j])
        	{
        		dist[j]=newdist;//修改特殊路径 
        		prev[j]=u;
			}
		}
    	
	}
}
int main ()
{
	int i,j,k;
	int c[20][20];
	int dist[20],prev[20];
	int n,line;//n为顶点个数，line为边的条数 
	int m,pre;
	printf("请输入顶点个数为:\n");
	scanf("%d",&n);
	printf("请输入边的条数为:\n");
	scanf("%d",&line);
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	       c[i][j]=maxint;
	printf("请输入各边的权值为：\n");
	for(k=1;k<=line;k++)
	{
		scanf("%d%d",&i,&j);
		scanf("%d",&c[i][j]);
	}   
	Dijkstra(n,V,dist,prev,c);
	for(i=1;i<=n;i++)
	{
		printf("%d到%d的最短路径为：",V,i);
		printf("%d\n",dist[i]);
		pre=prev[i];
		printf("路径为：%4d",i);
		while(pre!=0)
		{
			printf("%4d",pre);
			pre=prev[pre];
		}
		printf("\n");
	}    
	       
}
