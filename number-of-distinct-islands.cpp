#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <sstream>
using namespace std;

string bfs(vector<vector<int>> &grid, vector<pair<int, int>> &directions, vector<vector<bool>> &vis, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;

    ostringstream path;
    path << "o"; // Start indicator for each island's traversal

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (int d = 0; d < directions.size(); ++d)
        {
            int newR = u.first + directions[d].first;
            int newC = u.second + directions[d].second;

            if (newR >= 0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() && grid[newR][newC] && !vis[newR][newC])
            {
                vis[newR][newC] = true;
                q.push({newR, newC});
                path << directions[d].first << directions[d].second; // Append relative position
            }
        }
        path << "b"; // Backtracking indicator
    }

    return path.str();
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> directions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    unordered_set<string> uniqueIslands;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] && !vis[i][j])
            {
                string shape = bfs(grid, directions, vis, i, j);
                uniqueIslands.insert(shape);
            }
        }
    }

    return uniqueIslands.size();
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};

    cout << countDistinctIslands(grid) << endl;
    return 0;
}