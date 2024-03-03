#include <iostream>
#include <vector>
using namespace std;

// Runtime 5 ms. Beats 37.22% of users with C++
// Memory 15.12 MB. Beats 5.28% of users with C++
int findMin(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[0];
}
int main()
{
    vector<int> nums{2, 2, 2, 0, 1};
    cout << findMin(nums) << endl;
    return 0;
}