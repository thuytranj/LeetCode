#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &mat)
{
    vector<pair<int, int>> pos{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int n = mat.size(), m = mat[0].size();
    int fresh = 0;
    queue<pair<int, int>> rot;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 2)
                rot.push({i, j});
            else if (mat[i][j] == 1)
                fresh++;
        }
    }
    if (fresh == 0)
        return 0;

    int res = 0;
    while (!rot.empty() && fresh > 0)
    {
        int s = rot.size();

        for (int k = 0; k < s; k++)
        {
            int r = rot.front().first;
            int c = rot.front().second;
            rot.pop();

            for (auto i : pos)
            {
                int newR = r + i.first;
                int newC = c + i.second;
                if (newR >= 0 && newR < n && newC >= 0 && newC < m && mat[newR][newC] == 1)
                {
                    fresh--;
                    rot.push({newR, newC});
                    mat[newR][newC] = 2;
                }
            }
        }
        if (!rot.empty())
            res++;
    }

    if (fresh > 0)
        return -1;
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n);

    for (int i = 0; i < n; i++)
    {
        mat[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << orangesRotting(mat) << endl;
    return 0;
}