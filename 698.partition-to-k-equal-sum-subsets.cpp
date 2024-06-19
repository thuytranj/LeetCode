#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> nums, vector<int> &sum, vector<bool> &check, int pos, int target, bool &res)
{
    if (pos == nums.size())
    {
        res = 1;
        return;
    }
    for (int i = 0; i < sum.size(); i++)
    {
        if (sum[i] + nums[pos] <= target)
        {
            if (!check[pos])
            {
                check[pos] = 1;
                sum[i] += nums[pos];
                solve(nums, sum, check, pos + 1, target, res);
                if (res)
                    return;
                sum[i] -= nums[pos];
                check[pos] = 0;
            }
        }
        if (sum[i] == 0)
            break;
    }
}
bool canPartitionKSubsets(vector<int> &nums, int k)
{
    vector<int> sum(k, 0);
    vector<bool> check(nums.size(), 0);
    bool res = 0;
    int tmp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        tmp += nums[i];
    }
    if (tmp%k!=0) return false;
    solve(nums, sum, check, 0, tmp / k, res);
    return res;
}
int main () {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n;i++) {
        cin >> nums[i];
    }
    if (canPartitionKSubsets(nums, k))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}