#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &board, vector<vector<bool>> &vis, vector<pair<int, int>> &dir, int x, int y)
{
    vis[x][y] = true;

    for (auto i : dir)
    {
        int nr = x + i.first;
        int nc = y + i.second;

        if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] == 'O' && !vis[nr][nc])
        {
            dfs(board, vis, dir, nr, nc);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    if (board.empty() || board[0].empty())
        return;

    int n = board.size(), m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<pair<int, int>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O' && !vis[i][0])
            dfs(board, vis, dir, i, 0);
        if (board[i][m - 1] == 'O' && !vis[i][m - 1])
            dfs(board, vis, dir, i, m - 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O' && !vis[0][i])
            dfs(board, vis, dir, 0, i);
        if (board[n - 1][i] == 'O' && !vis[n - 1][i])
            dfs(board, vis, dir, n - 1, i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O' && !vis[i][j])
                board[i][j] = 'X';
        }
    }
}

int main()
{
    vector<vector<char>> mat {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    solve(mat);

    for (int i = 0; mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j];
        cout << endl;
    }
    return 0;
}