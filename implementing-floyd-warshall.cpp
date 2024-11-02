#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> adj, vector<vector<int>> &mat, int x)
{
    vector<int> dis(mat.size(), INT_MAX);
    dis[x] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});

    while (!pq.empty())
    {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (w > dis[v])
            continue;
        for (int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i].first;
            int cost = adj[v][i].second;

            if (w + cost < dis[u])
            {
                dis[u] = w + cost;
                pq.push({dis[u], u});
            }
        }
    }

    for (int i = 0; i < mat.size(); i++)
    {
        if (dis[i] != INT_MAX)
            mat[x][i] = dis[i];
    }
}
void shortestDistance(vector<vector<int>> &mat)
{
    vector<vector<pair<int, int>>> adj(mat.size());

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] > 0)
                adj[i].push_back({j, mat[i][j]});
        }
    }

    for (int i = 0; i < mat.size(); i++)
    {
        dijkstra(adj, mat, i);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n);

    for (int i = 0; i < n; i++)
    {
        mat[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }

    shortestDistance(mat);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }

    return 0;
}