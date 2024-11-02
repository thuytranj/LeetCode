#include <iostream>
#include <vector>
#include <map>
using namespace std;

int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    if (edges.empty())
        return 0;
    vector<int> dist(n, INT_MAX);
    dist[edges[0][0]] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (const auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (const auto &it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> edges = {{0, 1, -1}, {1, 2, -2}, {2, 0, -3}};
    cout << isNegativeWeightCycle(3, edges) << endl;
    return 0;
}