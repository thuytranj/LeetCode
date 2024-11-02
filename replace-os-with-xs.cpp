#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs (vector<vector<char>> mat, vector<vector<char>> &vis, vector<pair<int, int>> &index, int x, int y)
{
    int r = mat.size(), c = mat[0].size();

    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 'O';

    while (!q.empty())
    {
        auto tmp = q.front();
        q.pop();

        for (auto i : index)
        {
            int newR = tmp.first + i.first;
            int newC = tmp.second + i.second;

            if (newR >= 0 && newR < r && newC >= 0 && newC < c && mat[newR][newC] == 'O' && vis[newR][newC]=='X')
            {
                vis[newR][newC] = 'O';
                q.push({newR, newC});
            }
        }
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<char>> vis(n, vector<char>(m, 'X'));
    vector<pair<int, int>> index = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (int i = 0; i < n; i++)
    {
        if (mat[i][m - 1] == 'O' && vis[i][m - 1] == 'X')
            bfs(mat, vis, index, i, m-1);

        if (mat[i][0] == 'O' && vis[i][0] == 'X')
            bfs(mat, vis, index, i, 0);
    }

    for (int i = 1; i < m-1; i++)
    {
        if (mat[0][i] == 'O' && vis[0][i] == 'X')
            bfs(mat, vis, index, 0, i);

        if (mat[n - 1][i] == 'O' && vis[n - 1][i] == 'X')
            bfs(mat, vis, index, n - 1, i);
    }

    return vis;
}
int main()
{
    vector<vector<char>> mat = {{'X', 'O', 'X', 'X'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'X', 'O', 'O'}};

    vector<vector<char>>
        res = fill(5, 4, mat);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}