#include <iostream>
#include <vector>
using namespace std;

// Runtime 75 ms. Beats 77.44% of users with C++
// Memory 68.14 MB. Beats 78.53% of users with C++

int maxSubArray(vector<int> &nums)
{
    if (nums.size() > 1)
    {
        int sum = 0, max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > max)
                max = sum;
            if (sum < 0 && i != nums.size() - 1)
                sum = 0;
        }
        return max;
    }
    else
        return nums[0];
}
int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray (nums) <<endl;
    return 0;
}