#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
    vector<pair<int, int>> index = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({grid[0][0], {0, 0}});
    dis[0][0] = grid[0][0];

    while (!pq.empty())
    {
        int w = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        for (auto i : index)
        {
            int newR = r + i.first;
            int newC = c + i.second;

            if (newR >= 0 && newR < n && newC >= 0 && newC < n && dis[newR][newC] > dis[r][c] + grid[newR][newC])
            {
                dis[newR][newC] = dis[r][c] + grid[newR][newC];
                pq.push({dis[newR][newC], {newR, newC}});
            }
        }
    }

    return dis[n - 1][n - 1];
}
int main()
{
    vector<vector<int>> grid = {{4, 4}, {3, 7}};
    cout << minimumCostPath(grid) << endl;
    return 0;
}