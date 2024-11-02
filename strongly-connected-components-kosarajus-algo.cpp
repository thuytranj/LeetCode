#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topo(vector<vector<int>> &adj, vector<bool> &vis, stack<int> &s, int x)
{
    vis[x] = 1;

    for (int i : adj[x])
    {
        if (!vis[i])
            topo(adj, vis, s, i);
    }

    s.push(x);
}

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int x)
{
    vis[x] = 1;

    for (int i : adj[x])
    {
        if (!vis[i])
            dfs(adj, vis, i);
    }
}

vector<vector<int>> transposeGraph(vector<vector<int>> &adj, int V)
{
    vector<vector<int>> tg(V);

    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            tg[adj[i][j]].push_back(i);
        }
    }

    return tg;
}
int kosaraju(int V, vector<vector<int>> &adj)
{
    int cnt = 0;
    stack<int> s;
    vector<bool> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            topo(adj, vis, s, i);
    }

    vector<vector<int>> tg = transposeGraph(adj, V);
    vis.assign(V, 0);

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        if (!vis[u])
        {
            cnt++;
            dfs(tg, vis, u);
        }
    }

    return cnt;
}
int main()
{
    vector<vector<int>> adj = {{1}, {2}, {0}};
    int V = 3;
    cout << kosaraju(V, adj) << endl;
    return 0;
}