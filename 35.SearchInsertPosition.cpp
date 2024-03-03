#include <iostream>
#include <vector>
using namespace std;

// Runtime 3 ms. Beats 72.69% of users with C++
// Memory 12.04 MB. Beats 33.59% of users with C++

int searchInsert(vector<int> &nums, int target)
{
    if (target > nums[nums.size() - 1])
        return nums.size();
    else if (target < nums[0])
        return 0;
    else
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target || (nums[m] > target && nums[m - 1] < target))
                return m;
            else
            {
                if (nums[m] < target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> nums{1, 3, 5, 6};
    int target = 2;
    cout << searchInsert(nums, target) << endl;
    return 0;
}