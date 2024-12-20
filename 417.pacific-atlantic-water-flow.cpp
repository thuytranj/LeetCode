#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, vector<pair<int, int>> &dir, queue<pair<int, int>> &q)
{
    int n = heights.size(), m = heights[0].size();
    while (!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        vis[tmp.first][tmp.second] = true;

        for (const auto &it : dir)
        {
            int newX = tmp.first + it.first;
            int newY = tmp.second + it.second;

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY] && heights[newX][newY] >= heights[tmp.first][tmp.second])
            {
                q.push({newX, newY});
            }
        }
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>> res;
    int n = heights.size(), m = heights[0].size();
    vector<vector<bool>> pacific(n, vector<bool>(m, false)), atlantic(n, vector<bool>(m, false));
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    queue<pair<int, int>> pacificQ, atlanticQ;

    for (int i = 0; i < n; i++)
    {
        pacificQ.push({i, 0});
        atlanticQ.push({i, m - 1});
    }

    for (int i = 0; i < m; i++)
    {
        pacificQ.push({0, i});
        atlanticQ.push({n - 1, i});
    }

    bfs(heights, pacific, dir, pacificQ);
    bfs(heights, atlantic, dir, atlanticQ);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (pacific[i][j] && atlantic[i][j])
                res.push_back({i, j});
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> res = pacificAtlantic(heights);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << ' ' << res[i][1] << endl;
    }
    return 0;
}