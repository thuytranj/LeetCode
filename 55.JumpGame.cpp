#include <iostream>
#include <vector>
using namespace std;

// Runtime 374 ms. Beats 15.35% of users with C++
// Memory 51.2 MB. Beats 18.02% of users with C++
bool canJump(vector<int> &nums)
{
    vector<bool> res{};
    res.resize(nums.size());
    res[0] = true;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (res[i])
        {
            if (nums.size() - 1 - i <= nums[i])
                return true;
            for (int j = 1; j <= nums[i]; j++)
            {
                res[i + j] = true;
            }
        }
    }
    return res[nums.size() - 1];
}
int main()
{
    vector<int> nums{2, 3, 1, 1, 4};
    if (canJump(nums))
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}