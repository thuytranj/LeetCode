#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &cookies, int k, int &res, int &tmp, vector<int> &sum, int pos)
{
    if (pos == cookies.size())
    {
        int currentMax = *max_element(sum.begin(), sum.end());
        res = min(res, currentMax);
        return;
    }
    for (int i = 0; i < sum.size(); i++)
    {
        sum[i] += cookies[pos];
        solve(cookies, k, res, tmp, sum, pos + 1);
        sum[i] -= cookies[pos];
    }
}
int distributeCookies(vector<int> &cookies, int k)
{
    vector<int> sum(k, 0);
    int res = INT_MAX, tmp = INT_MAX;
    solve(cookies, k, res, tmp, sum, 0);
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << distributeCookies(nums, k) << endl;
    return 0;
}