#include <iostream>
#include <vector>
using namespace std;

// Runtime 59 ms. Beats 22.73% of users with C++
// Memory 41.48 MB. Beats 95.24% of users with C++

int firstMissingPositive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    bool Return = false;
    if (nums.size() == 1 && nums[0] == 1)
        return 2;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[0] > 1 || (nums[i] <= 0 && nums[i + 1] > 1))
        {
            return 1;
        }
        if (nums[i] > 0 && nums[i + 1] - nums[i] > 1)
        {
            return nums[i] + 1;
        }
    }
    if ((nums.size() == 1 && nums[0] > 1) || nums[nums.size() - 1] + 1 <= 0)
        return 1;
    else
        return nums[nums.size() - 1] + 1;
}
int main()
{
    vector<int> nums{7, 8, 9, 11, 12};
    cout << firstMissingPositive (nums)<<endl;
    return 0;
}