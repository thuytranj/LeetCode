#include <iostream>
#include <vector>

using namespace std;
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return max(nums[0], nums[1]);
    vector<int> res1(nums.size() - 1, 0), res2(nums.size() - 1, 0);
    res1[0] = nums[0];
    res1[1] = max(nums[0], nums[1]);
    for (int i = 2; i < res1.size(); i++)
    {
        if (nums[i] + res1[i - 2] > res1[i - 1])
            res1[i] = res1[i - 2] + nums[i];
        else
            res1[i] = res1[i - 1];
    }

    res2[0] = nums[1];
    res2[1] = max(nums[1], nums[2]);
    for (int i = 2; i < res2.size(); i++)
    {
        if (nums[i + 1] + res2[i - 2] > res2[i - 1])
            res2[i] = res2[i - 2] + nums[i + 1];
        else
            res2[i] = res2[i - 1];
    }
    return max(res1[res1.size() - 1], res2[res2.size() - 1]);
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
    cout << rob(nums) << endl;
    return 0;
}