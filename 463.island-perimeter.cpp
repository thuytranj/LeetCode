#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int bfs(vector<vector<int>> &grid, vector<pair<int, int>> &dir, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = -1; 
    int cnt = 0;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (auto i : dir)
        {
            int nr = r + i.first;
            int nc = c + i.second;

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size())
            {
                if (grid[nr][nc] == 0)
                {
                    cnt++; 
                }
                else if (grid[nr][nc] == 1)
                {
                    q.push({nr, nc});
                    grid[nr][nc] = -1; 
                }
            }
            else
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int islandPerimeter(vector<vector<int>> &grid)
{
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                return bfs(grid, dir, i, j); 
            }
        }
    }

    return 0; 
}

int main()
{
    vector<vector<int>> grid = {{1, 1}, {1, 1}};
    cout << islandPerimeter(grid) << endl;
    return 0;
}