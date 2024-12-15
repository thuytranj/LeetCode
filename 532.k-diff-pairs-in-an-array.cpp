#include <iostream>
#include <vector>
using namespace std;
int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int pairs = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0 || nums[i] > nums[i - 1])
        {
            auto it = binary_search(nums.begin() + i + 1, nums.end(), nums[i] + k);
            if (it)
                pairs++;
        }
    }
    return pairs;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 1;
    cout << findPairs(nums, k) << endl;
    return 0;
}