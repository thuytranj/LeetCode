#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void dfs(vector<int> adj[], vector<bool> &vis, int x)
{
    vis[x] = 1;

    for (int i : adj[x])
    {
        if (!vis[i])
            dfs(adj, vis, i);
    }
}
int findMotherVertex(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    int res;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i]) {
            dfs(adj, vis, i);
            res=i;
        }
    }

    fill(vis.begin(), vis.end(), 0);
    dfs(adj, vis, res);

    for (bool i:vis) {
        if (!i) return -1;
    }
    return res;
}
int main()
{
    vector<int> adj[] = {{1}, {}, {1}};
    cout << findMotherVertex(3, adj) << endl;
    return 0;
}