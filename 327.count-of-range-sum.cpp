#include <iostream>
#include <vector>
using namespace std;

int countUseMerge(vector<long long> &nums, int left, int right, int lower, int upper)
{
    if (right - left <= 1)
        return 0;
    int mid = left + (right - left) / 2;

    int cnt = countUseMerge(nums, left, mid, lower, upper) + countUseMerge(nums, mid, right, lower, upper);

    int j = mid, k = mid, t = mid, r = 0;
    vector<long long> tmp(right - left);

    for (int i = left; i < mid; ++i)
    {
        while (k < right && nums[k] - nums[i] < lower)
            k++;
        while (j < right && nums[j] - nums[i] <= upper)
            j++;
        cnt += j - k;

        while (t < right && nums[t] < nums[i])
            tmp[r++] = nums[t++];
        tmp[r++] = nums[i];
    }

    copy(tmp.begin(), tmp.begin() + r, nums.begin() + left);
    return cnt;
}
int countRangeSum(vector<int> &nums, int lower, int upper)
{
    vector<long long> sum(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        sum[i + 1] = sum[i] + nums[i];
    }
    return countUseMerge(sum, 0, sum.size(), lower, upper);
}

int main()
{
    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;
    cout << countRangeSum(nums, lower, upper) << endl;
    return 0;
}