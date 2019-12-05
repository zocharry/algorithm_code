#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;
  
void Dijkstra(int n,int s,int *dist,int *prev,int w[][4])  
{  
    int maxint = 65535;  
    bool *visit = new bool[n];  
  
    for (int i = 0; i < n; i++)  
    {  
        dist[i] = w[s][i];  
        visit[i] = false;  
        if (dist[i] != maxint)  
        {  
            prev[i] = s;  
        }  
    }  
  
    dist[s] = 0;  
    visit[s] = true;  
    for (int i = 0; i < n; i++)  
    {  
        int temp = maxint;  
        int u = s;  
        for (int j = 0; j < n; j++)  
        {  
            if ((!visit[j]) && (dist[j] < temp))  
            {  
                u = j;  
                temp = dist[j];  
            }  
        }  
        visit[u] = true;  
        for (int j = 0; j < n; j++)  
        {  
            if (!visit[j])  
            {  
                int newdist = dist[u] + w[u][j];  
                if (newdist < dist[j])  
                {  
                    dist[j] = newdist;  
                    prev[j] = u;  
                }  
            }  
        }  
    }  
  
    delete []visit;  
}  
  
int main()  
{  
    int n,v,u;  
    int weight[4][4]={  
        0,2,65535,4,  
        2,0,3,65535,  
        65535,3,0,2,  
        4,65535,2,0  
        };  
    int q = 0;  
    int way[4];  
    int dist[4];  
    int prev[4];  
    int s = 1;  
    int d = 3;  
    Dijkstra(4, s, dist, prev, weight);  
    cout<<"The least distance from "<<s<<" to "<<d<<" is "<<dist[d]<<endl;  
    int w = d;  
    while (w != s)  
    {  
        way[q++] = prev[w];  
        w = prev[w];  
    }  
    cout<<"The path is ";  
    for (int j = q-1; j >= 0; j--)  
    {  
        cout<<way[j]<<" -> ";  
    }  
    cout<<d<<endl;  
  
    return 0;  
}
