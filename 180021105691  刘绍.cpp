#include <stdio.h>                                              
#define INFINITY 65535
typedef int VertexType;   
typedef int EdgeType;   
typedef struct    
{  
 
    VertexType vexs[9];  
 
    EdgeType edges[9][9];   
 
    int vexnum,arcnum;    
 
}MGraph;  
 

 
void CreateGraph(MGraph *G)  
{   
    int i,j,k,weight;  
    int ch1,ch2;  
 
    printf("请输入顶点数和边数(输入格式为:顶点数,边数):");  
 
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));  
 
    printf("请输入顶点名称(输入格式为:a,b,c...)：");  
 
    for(i=0;i<G->vexnum;i++)  
    {  
       getchar();
       scanf("%d",&(G->vexs[i]));  
    }  
		
    for(i=0;i<G->vexnum;i++)  
        for(j=0;j<G->vexnum;j++)  
        if(i==j)
        	G->edges[i][j]=0;
        else
            G->edges[i][j]=INFINITY;  
 
        printf("请输入每条边对应的两个顶点名称(输入格式为:a,b):\n");  
 
        for(k=0;k<G->arcnum;k++)  
        {  
           // getchar();  
            printf("请输入第%d条边的两个顶点名称：",k+1);  
            scanf("%d,%d",&ch1,&ch2);  
            for(i=0;ch1!=G->vexs[i];i++);  
            for(j=0;ch2!=G->vexs[j];j++);  
            getchar(); 
			printf("请输入第%d条边的权值：",k+1);  
            scanf("%d",&weight);	
            G->edges[i][j]=weight; 
			G->edges[j][i]=weight;  
        }  
}  
 
void ShortestPath_Dijkstra(MGraph G,int v0,int* P,int* D)
{
	int v,w,k,min;
	int final[9];//final[w]=1表示已经得到v0到vw的最短路径
	for(v=0;v<G.vexnum;v++)
	{
		final[v]=0;
		D[v]=G.edges[v0][v];
		P[v]=0;
	 } 
	 D[v0]=0;
	 final[v0]=1;

	 for(v=1;v<G.vexnum;v++)
	 {
	 	min=INFINITY;
	 	for(w=0;w<G.vexnum;w++)
	 	{
	 		if(!final[w]&&D[w]<min)
	 		{
	 			k=w;
	 			min=D[w];
			 }
		 }
		 final[k]=1;
		 for(w=0;w<G.vexnum;w++)
		 {
		 	if(!final[w]&&(min+G.edges[k][w]<D[w]))
		 	{
		 		D[w]=min+G.edges[k][w];
		 		P[w]=k;
			 }
		 }
	 }
}
int main()  
{  
    MGraph G;  
    CreateGraph(&G);
    int v0=0,j;
    int P[9];
    int D[9];
    ShortestPath_Dijkstra(G,v0,P,D);
    for(j=0;j<9;j++)
    	{
    		printf("%d,",P[j]);
		}
		printf("\n");
	for(j=0;j<9;j++)
    	{
    		printf("%d,",D[j]);
		}
}

