#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
int bfs(unordered_map<int, vector<int>> &adj, vector<bool> &vis, int x)
{
    queue<int> q;
    q.push(x);
    int h = 0;

    while (!q.empty())
    {
        int s = q.size();
        h++;
        for (int i = 0; i < s; i++)
        {
            int u = q.front();
            vis[u] = 1;
            q.pop();

            for (int v : adj[u])
            {
                if (!vis[v])
                    q.push(v);
            }
        }
    }

    return h;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
        return {0};

    // Xây dựng danh sách kề và mảng bậc
    unordered_map<int, vector<int>> adj;
    vector<int> degree(n, 0);
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        degree[e[0]]++;
        degree[e[1]]++;
    }

    queue<int> leaves;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            leaves.push(i);
    }

    while (n > 2)
    {
        int countLeaves = leaves.size();
        n -= countLeaves;

        for (int i = 0; i < countLeaves; i++)
        {
            int leaf = leaves.front();
            leaves.pop();
            for (int u : adj[leaf])
            {
                degree[u]--;
                if (degree[u] == 1)
                    leaves.push(u);
            }
        }
    }

    vector<int> res;
    while (!leaves.empty())
    {
        res.push_back(leaves.front());
        leaves.pop();
    }
    return res;
}

int main()
{
    vector<vector<int>> edges{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    int n = 6;
    vector<int> res = findMinHeightTrees(n, edges);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}