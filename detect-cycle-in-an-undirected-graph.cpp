#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool bfs(vector<vector<int>> adj, vector<bool> &vis, int x)
{
    queue<pair<int, int>> q;
    q.push({x, -1});
    vis[x] = 1;

    while (!q.empty())
    {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto i : adj[u])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push({i, u});
            }
            else if (i != parent)
                return 1;
        }
    }

    return 0;
}

bool cycle(vector<vector<int>> adj)
{
    vector<bool> vis(adj.size(), 0);

    for (int i = 0; i < adj.size(); i++)
    {
        if (!vis[i])
        {
            if (bfs(adj, vis, i))
                return 1;
        }
    }

    return 0;
}
int main()
{
    return 0;
}