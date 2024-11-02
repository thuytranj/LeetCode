#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    if (KnightPos == TargetPos)
        return 0;
    vector<pair<int, int>> index{{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    vector<vector<bool>> vis(N, vector<bool>(N, 0));
    int cnt = 0;
    pair<int, int> targetPos = {N - TargetPos[1], TargetPos[0] - 1};
    queue<pair<int, int>> q;
    q.push({N - KnightPos[1], KnightPos[0] - 1});
    vis[N - KnightPos[1]][KnightPos[0] - 1] = 1;

    while (!q.empty())
    {
        int s = q.size();
        cnt++;

        for (int i = 0; i < s; i++)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (auto j : index)
            {
                int newR = r + j.first;
                int newC = c + j.second;

                if (newR >= 0 && newR < N && newC >= 0 && newC < N && !vis[newR][newC])
                {
                    vis[newR][newC] = 1;
                    if (newR == targetPos.first && newC == targetPos.second)
                    {
                        return cnt;
                    }
                    q.push({newR, newC});
                }
            }
        }
    }

    return -1;
}
int main()
{
    vector<int> KnightPos = {1, 1};
    vector<int> TargetPos = {1, 1};
    int N = 6;
    cout << minStepToReachTarget(KnightPos, TargetPos, N) << endl;
    return 0;
}