#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &directions, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    int cnt = 1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;

        for (auto dir : directions)
        {
            int nr = r + dir.first;
            int nc = c + dir.second;

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && !vis[nr][nc])
            {
                q.push({nr, nc});
                vis[nr][nc] = 1;
                cnt++;
            }
        }
        q.pop();
    }

    return cnt;
}
int findMaxArea(vector<vector<int>> &grid)
{
    int res = 0, n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] && !vis[i][j])
            {
                res = max(res, bfs(grid, vis, directions, i, j));
            }
        }
    }

    return res;
}
int main()
{
    vector<vector<int>> grid = {{0, 1}};
    cout << findMaxArea(grid) << endl;
    return 0;
}