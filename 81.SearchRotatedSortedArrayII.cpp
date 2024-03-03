#include <iostream>
#include <vector>
using namespace std;

// Runtime 5 ms. Beats 50.19% of users with C++
// Memory 16.66 MB. Beats 20.23% of users with C++

bool search(vector<int> &nums, int target)
{
    int i = 0, t = nums.size();
    while (i < t && (i == t - 1 || nums[i] <= nums[i + 1]))
    {
        nums.push_back(nums[i]);
        i++;
    }
    if (i < t - 1)
    {
        nums.push_back(nums[i]);
        i++;
    }
    int l = i, r = nums.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[m] == target)
            return true;
        else if (nums[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}
int main()
{
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    int target=0;
    if (search (nums, target))
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}