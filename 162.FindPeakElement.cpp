#include <iostream>
#include <vector>
using namespace std;

// Runtime 3 ms. Beats 65.65% of users with C++
// Memory 11.14 MB. Beats 57.79% of users with C++
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1 || nums[0] > nums[1])
        return 0;
    if (nums[nums.size() - 1] > nums[nums.size() - 2])
        return nums.size() - 1;
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (m + 1 < nums.size() && m >= 1 && nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
            return m;
        if (m + 1 < nums.size() && nums[m] < nums[m + 1])
            l = m + 1;
        else if (m >= 1 && nums[m - 1] > nums[m])
            r = m - 1;
    }
    return -1;
}
int main()
{
    vector<int> nums{1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement (nums)<<endl;
     return 0;
}