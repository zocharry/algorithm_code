#include<stdio.h> 
void bt(int k,int prev[]){
	if(prev[k]==1)
	    printf("1->%d",k); 
	else{
		bt(prev[k],prev);
		printf("->%d",k);
	}
}
template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type **c,int maxint){
	bool s[maxint];
	for(int i=1;i<=n;i++){
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint)
		    prev[i]=0;
		else
		    prev[i]=v;
	}
	dist[v]=0;s[v]=true;
	for(int i=1;i<n;i++){
		int temp =maxint;
		int u=v;
		for(int j=1;j<=n;j++)
			if((!s[j])&&(dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j])&&(c[u][j]<maxint)){
					Type newdist=dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
		}
	}
	for(int i=2;i<=n;i++){
	    printf("从1点到%d点最短路径合%d \n",i,dist[i]);
	}
	for(int i=2;i<=n;i++){
	    printf("从1到%d点的路径为 ",i);
	    bt(i,prev);
	    printf("\n");
	}
}
int main(){
	int n=5;
	int v=1;
	int maxint=100000;
	int dist[n+1];
	int prev[n+1];
	int **a=new int*[n+1];
    for(int i=1;i<=n;i++){
        a[i]=new int[n+1];
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        a[i][j]=maxint;
	a[1][2]=10;
	a[1][4]=30;
	a[1][5]=100;
	a[2][3]=50;
	a[3][5]=10;
    a[4][3]=20;
	a[4][5]=60; 
	printf("该图的邻接矩阵为：\n"); 
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++)
	        printf("%d ",a[i][j]);
	    printf(" \n");
	}
	Dijkstra(n,v,dist,prev,a,maxint);
	delete []a;
}
