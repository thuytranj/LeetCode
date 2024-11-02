#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> &grid)
{
    vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), -1));
    queue<pair<int, int>> q;
    vector<pair<int, int>> adj = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j])
            {
                res[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto u = q.front();
            q.pop();

            for (auto i : adj)
            {
                int newR = u.first + i.first;
                int newC = u.second + i.second;

                if (newR >= 0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() && res[newR][newC] == -1)
                {
                    res[newR][newC] = res[u.first][u.second] + 1;
                    q.push({newR, newC});
                }
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> grid = {{1, 0, 1},
                                {1, 1, 0},
                                {1, 0, 0}};
    vector<vector<int>>
        res = nearest(grid);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}