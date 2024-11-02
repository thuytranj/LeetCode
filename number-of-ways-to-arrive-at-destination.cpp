#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto i : roads)
    {
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> countPaths(n, 0), dist(n, INT_MAX);
    countPaths[0] = 1;
    dist[0] = 1;
    q.push({0, 0}); //  {dist, vertex}

    while (!q.empty())
    {
        int u = q.top().second;
        int d = q.top().first;
        q.pop();

        if (d > dist[u])
            continue;

        for (auto i : adj[u])
        {
            int v = i.first, w = i.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                countPaths[v] = countPaths[u];
                q.push({dist[v], v});
            }
            else if (dist[u] + w == dist[v])
                countPaths[v] = (countPaths[v] + countPaths[u]) % (int(1e9 + 7));
        }
    }

    return countPaths[n - 1];
}
int main()
{
    vector<vector<int>> roads = {{0, 5, 8}, {0, 2, 2}, {0, 1, 1}, {1, 3, 3}, {1, 2, 3}, {2, 5, 6}, {3, 4, 2}, {4, 5, 2}};
    cout << countPaths(6, roads) << endl;
    return 0;
}