#include <iostream>
#include <vector>
using namespace std;
int countSame(vector<int> &a, vector<int> &b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b[i])
            cnt++;
    }
    return cnt;
}
void solve(vector<vector<int> > &students, vector<vector<int> > &mentors, int &res, int sum, vector<bool> &used, int pos)
{
    if (pos == students.size())
    {
        res = max(res, sum);
        return;
    }
    for (int i = 0; i < mentors.size(); i++)
    {
        if (!used[i])
        {
            int cnt = countSame(students[pos], mentors[i]);
            used[i] = true;
            solve(students, mentors, res, sum + cnt, used, pos + 1);
            used[i] = false;
        }
    }
}
int maxCompatibilitySum(vector<vector<int> > &students, vector<vector<int> > &mentors)
{
    vector<bool> used(students.size(), 0);
    int res = INT_MIN;
    solve(students, mentors, res, 0, used, 0);
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > students(n), mentors(n);
    for (int i = 0; i < n; i++)
    {
        students[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> students[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        mentors[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> mentors[i][j];
        }
    }
    cout << maxCompatibilitySum(students, mentors) << endl;
    return 0;
}