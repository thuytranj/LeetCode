#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    vector<int> dis(V, INT_MAX);
    dis[0] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    for (int i=0;i<V; i++) {
        for (auto edge:edges[0]) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dis[u]!=INT_MAX && dis[u]+w<dis[v]) {
                dis[v]=dis[u]+w;
            }
        }
    }

    for (auto edge : edges[0])
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dis[u] != INT_MAX && dis[u] + w < dis[v])
            return vector<int>{-1};
    }

    return dis;
}
int main () {
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i=0;i<m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    return 0;
}