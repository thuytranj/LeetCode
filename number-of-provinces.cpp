#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs (vector<vector<int>> adj, vector<bool> &vis, int x) {
    queue<int> q;
    q.push(x);
    vis[x]=1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u]=1;

        for (int i=0;i<adj[u].size();i++) {
            if (adj[u][i]!=x && adj[u][i]==1 && !vis[adj[u][i]]) {
                vis[adj[u][i]]=1;
                q.push(i);
            }
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V)
{
    int cnt=0;
    vector<bool> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        cnt++;
        if (!vis[i])
            bfs(adj, vis, i);
    }
    
    return cnt;
}
int main () {
    return 0;
}