#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &dir, int x, int y)
{
    vis[x][y] = 1;

    for (auto i : dir)
    {
        int nr = x + i.first;
        int nc = y + i.second;

        if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1' && !vis[nr][nc])
            dfs(grid, vis, dir, nr, nc);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int res = 0;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1' && !vis[i][j])
            {
                dfs(grid, vis, dir, i, j);
                res++;
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid) << endl;
    return 0;
}