#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, vector<pair<int, int>> &dir, int x, int y, int &res)
{
    if (dp[x][y] != -1)
        return;
    dp[x][y] = 1;

    for (auto i : dir)
    {
        int nr = x + i.first;
        int nc = y + i.second;

        if (nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size() && matrix[nr][nc] > matrix[x][y])
        {
            dfs(matrix, dp, dir, nr, nc, res);
            dp[x][y] = max(dp[x][y], 1 + dp[nr][nc]);
        }
    }

    res = max(res, dp[x][y]);
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int res = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            dfs(matrix, dp, dir, i, j, res);
        }
    }

    return res;
}
int main()
{
    vector<vector<int>> matrix = {{7, 8, 9}, {9, 7, 6}, {7, 2, 3}};
    cout << longestIncreasingPath(matrix) << endl; // Output: 4
    return 0;
}