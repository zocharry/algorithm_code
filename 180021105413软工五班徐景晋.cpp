#include<iostream>
#include<climits>
#include<vector>
const int M=100;
using namespace std;
struct node{//顶点信息 
	int father;//该节点的直接父节点 
	int cost;//该节点到源结点的最短权值 
}; 
struct edge{//所有边都会加入到数组中去，数组下标为该边的起点 
	int dest;//边的结束点的下标 
	int cost;
};
node vertex[M];
bool isVisited[M]={0};//表示某个节点是不是被访问过 
vector<edge> graph[M];//挂链表的形式保存图，因为要修改某个节点领接节点的值，所以必须保存图 
void printVertex(int v){//输出顶点到源结点的最小距离 
	for(int i=1;i<=v;i++)
	cout<<i<<":"<<vertex[i].cost<<"   "<<vertex[i].father<<endl;
} 
void init(int v,int s){//v个节点，对所有节点初始化,s为起点 
	for(int i=1;i<=v;i++){
		vertex[i].cost=INT_MAX;//所有节点的权值都是∞ 
		vertex[i].father=i;//父节点都是节点本身 
	}
	vertex[s].cost=0;//源结点的权值为0 
}
int getMin(int v){//获取没有访问过的最小节点 
	int res=INT_MAX;
	int index=-1;
	for(int i=1;i<=v;i++){
		if((isVisited[i]==0)&&(res>=vertex[i].cost)){
			res=vertex[i].cost;
			index=i;
		}
	}
	isVisited[index]=1;
	return index;
}
void relax(int u){//对和u相连接的所有节点进行松弛 
	int len=graph[u].size();
	for(int i=0;i<len;i++){
		int des=(graph[u][i]).dest;
		if((vertex[u].cost!=INT_MAX)&&(vertex[des].cost>vertex[u].cost+(graph[u][i]).cost)){
			vertex[des].cost=vertex[u].cost+(graph[u][i]).cost;
			vertex[des].father=u;
		}
	}
}
void dijkstra(int v,int e,int s){//时间复杂度为：O(V^2+E) 
	init(v,s);//初始化 
	for(int i=1;i<=v;i++){//一共有V个节点，每次取出一个节点，因此一共需要执行V次 
		int u=getMin(v);//取得离源结点最近的节点 
		relax(u);//松弛所有与源结点相邻的节点 
	}
}
void printPath(int startPoint,int destination){
	if(destination==startPoint)
		cout<<destination;
	else{
		printPath(startPoint,vertex[destination].father);
		cout<<"-->"<<destination;
	}
}
 
void printRoad(int v,int s){
	for(int i=1;i<=v;i++){
		cout<<"from "<<s<<" to "<<i<<" smallest cost:"<<vertex[i].cost<<".path:";//输出最少的费用   从那到哪 
		printPath(s,i);
		cout<<endl;	
	}
}
int main(){
	int v,e,s;//v个顶点e条边 s为起始点
	cin>>v>>e>>s;//输入三个书，最好小 大 小 比如 6 6 1 
	int a,b,c;//a到b的花费为c 
	edge temp;
	for(int i=1;i<=e;i++){
		cin>>a>>b>>c;//加权 
		temp.dest=b;
		temp.cost=c;
		graph[a].push_back(temp);
	}
	dijkstra(v,e,s);
	printRoad(v,s);
}


