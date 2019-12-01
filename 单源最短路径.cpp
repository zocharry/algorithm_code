
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
 
using namespace std;
 
struct edge{
	int to, cost;
};
 
typedef pair<int, int> P;
const int MAX = 10001;
const int INF = 0x3f3f3f3f; 
 
vector<edge> G[MAX]; 
int d[MAX];
int used[MAX];
int V; // Number of vertices
int E; // Number of edges
int s; // Point of departure;    The vertices here are from 0 to n
 
void creat(){
	cout<<"Please enter the number of vertices \ number of edges \ starting point (separated by Enter): ";
	cin >> V >> E >> s;
	cout <<"Please enter a weight between the two vertices "<<endl;
	cout <<"(for example, enter a weight of 0 to 1: 0 1 10, separated by a space): "<<endl;
	for(int i = 0; i < E; ++i){
		int from, to, cost;
		cin >> from >> to >> cost;
		edge e;
		e.to = to;
		e.cost = cost;
		G[from].push_back(e);
	}
}
 
void Dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que; 
    fill(d, d + V, INF);
    que.push(P(0, s));
	d[s] = 0;
 
	while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second; 
        if(d[v] < p.first) continue; 
        for(int i = 0; i < (int)G[v].size(); ++i){
            edge e = G[v][i]; 
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
	}
}
 
void solve(){
	creat();
	Dijkstra(s);
	for(int i = 0; i < V; ++i) cout << d[i] << ' ';  
}
int main(){
	solve();
	return 0;
}


 
