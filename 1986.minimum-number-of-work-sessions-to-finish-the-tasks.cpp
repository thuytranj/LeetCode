#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &tasks, int sessionTime, int &res, vector<int> &cur, int pos)
{
    if (pos == tasks.size())
    {
        res = min(res, (int)cur.size());
        return;
    }
    for (int i = 0; i < cur.size(); i++)
    {
        if (cur[i] + tasks[pos] <= sessionTime)
        {
            cur[i] += tasks[pos];
            solve(tasks, sessionTime, res, cur, pos + 1);
            cur[i] -= tasks[pos];
        }
    }
    cur.push_back(tasks[pos]);
    solve(tasks, sessionTime, res, cur, pos + 1);
    cur.pop_back();
}
int minSessions(vector<int> &tasks, int sessionTime)
{
    int res = INT_MAX;
    vector<int> cur(1, 0);
    solve(tasks, sessionTime, res, cur, 0);
    return res;
}

int main()
{
    int n, sessionTime;
    cin >> n >> sessionTime;
    vector<int> tasks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i];
    }
    cout << minSessions(tasks, sessionTime) << endl;
    return 0;
}