#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge{
    int u,v,w;
};

int findParent(int parent[],int x){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent,parent[x]);
}

void kruskal(int n, vector<Edge>& edges){
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){return a.w < b.w;});
    int parent[n];
    for(int i=0;i<n;i++) parent[i]=i;
    int cost=0;
    for(auto e:edges){
        int p1=findParent(parent,e.u);
        int p2=findParent(parent,e.v);
        if(p1!=p2){
            cost+=e.w;
            parent[p1]=p2;
        }
    }
    cout<<cost<<endl;
}

void prim(int n, vector<vector<pair<int,int>>>& adj){
    vector<int> vis(n,0), dist(n,1e9);
    dist[0]=0;
    int cost=0;
    for(int i=0;i<n;i++){
        int u=-1;
        for(int j=0;j<n;j++){
            if(!vis[j] && (u==-1 || dist[j]<dist[u])) u=j;
        }
        vis[u]=1;
        cost+=dist[u];
        for(auto x:adj[u]){
            int v=x.first, w=x.second;
            if(!vis[v] && w<dist[v]) dist[v]=w;
        }
    }
    cout<<cost<<endl;
}

void bfs(int n, vector<vector<int>>& g){
    vector<int> vis(n,0);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:g[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
    cout<<endl;
}

void dfsUtil(int u, vector<vector<int>>& g, vector<int>& vis){
    vis[u]=1;
    cout<<u<<" ";
    for(int v:g[u]){
        if(!vis[v]) dfsUtil(v,g,vis);
    }
}

void dfs(int n, vector<vector<int>>& g){
    vector<int> vis(n,0);
    dfsUtil(0,g,vis);
    cout<<endl;
}

void dijkstra(int n, vector<vector<pair<int,int>>>& adj){
    vector<int> dist(n,1e9);
    dist[0]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto p=pq.top(); pq.pop();
        int d=p.first, u=p.second;
        if(d!=dist[u]) continue;
        for(auto x:adj[u]){
            int v=x.first, w=x.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<vector<pair<int,int>>> adj(n);
    vector<Edge> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }

    bfs(n,g);
    dfs(n,g);
    kruskal(n,edges);
    prim(n,adj);
    dijkstra(n,adj);
}
