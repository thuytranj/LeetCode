#include <iostream>
#include <vector>
using namespace std;

// Runtime 71 ms. Beats 9.58% of users with C++
// Memory 10.49 MB. Beats 98.84% of users with C++

int threeSumClosest(vector<int> &nums, int target)
{
    int j, k;
    sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[nums.size() - 1];
    for (int i = 0; i < nums.size() - 2; i++)
    {
        j = i + 1;
        k = nums.size() - 1;
        while (j < k)
        {

            if (abs(target - nums[i] - nums[j] - nums[k]) < abs(closest - target))
                closest = nums[i] + nums[j] + nums[k];
            if (nums[i] + nums[j] + nums[k] > target)
                k--;
            else
                j++;
        }
    }
    return closest;
}
int main()
{
    vector<int> nums{0, 0, 0};
    int target = 1;
    cout << threeSumClosest(nums, target) << endl;
    return 0;
}