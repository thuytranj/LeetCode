#include <iostream>
#include <vector>
using namespace std;

// Runtime 18 ms. Beats 96.91% of users with C++
// Memory 30.45 MB. Beats 64.56% of users with C++

int minSubArrayLen(int target, vector<int> &nums)
{
    int l = 0, r = 0, sum = nums[0], min = INT_MAX;
    while (r < nums.size())
    {
        if (sum >= target)
        {
            if (r - l + 1 < min)
                min = r - l + 1;
            sum -= nums[l];
            l++;
        }
        else
        {
            if (r + 1 - l + 1 <= min)
            {
                r++;
                if (r < nums.size())
                    sum += nums[r];
            }
            else
            {
                sum -= nums[l];
                l++;
            }
        }
    }
    if (min != INT_MAX)
        return min;
    return 0;
}
int main()
{
    vector<int> nums{2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << minSubArrayLen (target, nums)<<endl;
    return 0;
}