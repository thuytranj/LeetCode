#include <iostream>
#include <vector>
using namespace std;

bool placeNumber(vector<int> &res, vector<bool> &used, int pos, int num)
{
    int size = res.size();
    if (res[pos] == -1 && (num == 1 || (pos + num < size && res[pos + num] == -1)))
    {
        res[pos] = num;
        if (num > 1)
        {
            res[pos + num] = num;
        }
        used[num] = true;
        return true;
    }
    return false;
}

bool solve(vector<int> &res, vector<bool> &used, int n, int pos)
{
    if (pos == res.size())
    {
        return true;
    }
    if (res[pos] != -1)
    {
        return solve(res, used, n, pos + 1);
    }
    for (int num = n; num >= 1; --num)
    {
        if (!used[num] && placeNumber(res, used, pos, num))
        {
            if (solve(res, used, n, pos + 1))
            {
                return true;
            }
            res[pos] = -1;
            if (num > 1)
            {
                res[pos + num] = -1;
            }
            used[num] = false;
        }
    }
    return false;
}

vector<int> constructDistancedSequence(int n)
{
    vector<int> res(2 * n - 1, -1);
    vector<bool> used(n + 1, false);
    solve(res, used, n, 0);
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = constructDistancedSequence(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}