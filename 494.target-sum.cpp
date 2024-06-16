#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve(vector<int> &nums, int target, int index, int currentSum, int &res)
{
    if (index == nums.size())
    {
        if (currentSum == target)
        {
            res++;
        }
        return;
    }
    solve(nums, target, index + 1, currentSum + nums[index], res);
    solve(nums, target, index + 1, currentSum - nums[index], res);
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int res = 0;
    solve(nums, target, 0, 0, res);
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    cout << findTargetSumWays(nums, target) << endl;
    return 0;
}