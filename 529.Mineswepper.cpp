#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countMines(vector<vector<char>> &board, vector<pair<int, int>> &dir, int x, int y)
{
    int cnt = 0;

    for (auto &d : dir)
    {
        int nx = x + d.first, ny = y + d.second;
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'M')
        {
            cnt++;
        }
    }
    return cnt;
}

void bfs(vector<vector<char>> &board, vector<pair<int, int>> &dir, int x, int y, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        int cnt = countMines(board, dir, r, c);

        if (cnt > 0)
        {
            board[r][c] = char('0' + cnt);
        }
        else
        {
            board[r][c] = 'B';
            for (auto &d : dir)
            {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && !visited[nr][nc] && board[nr][nc] == 'E')
                {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
}

vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
{
    int x = click[0], y = click[1];

    if (board[x][y] == 'M')
    {
        board[x][y] = 'X';
        return board;
    }
    else if (board[x][y] == 'E')
    {
        vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        bfs(board, dir, x, y, visited);
    }

    return board;
}

int main()
{
    vector<vector<char>> board = {{'B', 'B', 'B', 'B', 'B', 'B', '1', 'E'}, {'B', '1', '1', '1', 'B', 'B', '1', 'M'}, {'1', '2', 'M', '1', 'B', 'B', '1', '1'}, {'M', '2', '1', '1', 'B', 'B', 'B', 'B'}, {'1', '1', 'B', 'B', 'B', 'B', 'B', 'B'}, {'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'}, {'B', '1', '2', '2', '1', 'B', 'B', 'B'}, {'B', '1', 'M', 'M', '1', 'B', 'B', 'B'}};
    vector<int> click = {0, 7};
    vector<vector<char>> res = updateBoard(board, click);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}