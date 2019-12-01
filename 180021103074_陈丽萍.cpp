#include<stdio.h>
#define maxint 1000
void Dijkstra(int n,int v,int dist[],int prev[],int c[5][5]){                                                                                                                                                                                                                       
	bool s[maxint];
	for(int i=1;i<=n;i++){
		dist[i]=c[i][i];
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
		for(int j=1;j<=n;j++){
			if((!s[j])&&(dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j])&&(c[u][j]<maxint)){
					int newdist=dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			}
		}
	}
}
void PrintPrev(int prev[],int n,int vn){
	int tmp=vn;
	int i,j;
	int tmpprv[n];
	for(i=0;i<n;i++)
		tmpprv[i]=0;
	tmpprv[0]=vn+1;
	for(i=0,j=1;j<n;j++){
		if(prev[tmp]!=-1&&tmp!=0){
			tmpprv[i]=prev[tmp]+1;
			tmp=prev[tmp];
			i++;
		}
		else break;
	}
	for(i=n-1;i>=0;i--){
		if(tmpprv[i]!=0){
			printf("v%d",tmpprv[i]);
			if(i)
				printf("-->");
		}
	}
	printf("-->V%d",vn+1);
}
int main(){
	int n=5;
	int v[n]={1,2,3,4,5};
	int c[n][n]={{0,10,maxint,30,100},
			{maxint,0,50,maxint,maxint},
			{maxint,maxint,0,maxint,10},
			{maxint,maxint,20,0,60},
			{maxint,maxint,maxint,maxint,0}
			};
	int *prev;//存放求得的最短路径 
	int *dist;//存放源到所有其他顶点之间的最短路径长度 
	Dijkstra(n,0,dist,prev,c);//求顶点V1到其余个点的最短路径 
	for(int i=0;i<5;i++){
	  	printf("%d-->%d:%d\t",v[0],v[i],dist[i]);
		PrintPrev(prev,0,i);
		printf("\n");
	}
	return 0;
}
