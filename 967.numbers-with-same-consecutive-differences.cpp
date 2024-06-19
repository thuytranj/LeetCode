#include <iostream>
#include <vector>
using namespace std;
void solve(int n, int k, vector<int> &res, string &cur)
{
    if (cur.size() == n)
    {
        res.push_back(stoi(cur));
        return;
    }
    if (cur[cur.size() - 1] - k - '0' >= 0)
    {
        cur.push_back(cur[cur.size() - 1] - k);
        solve(n, k, res, cur);
        cur.pop_back();
    }
    if (cur[cur.size() - 1] + k - '0' < 10 && cur[cur.size()-1]-k!=cur[cur.size()-1]+k)
    {
        cur.push_back(cur[cur.size() - 1] + k);
        solve(n, k, res, cur);
        cur.pop_back();
    }
}
vector<int> numsSameConsecDiff(int n, int k)
{
    vector<int> res;
    for (int i = 1; i < 10; i++)
    {
        string cur = to_string(i);
        solve(n, k, res, cur);
    }
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> res = numsSameConsecDiff(n, k);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}