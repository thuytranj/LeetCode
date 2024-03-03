#include <iostream>
#include <vector>
using namespace std;

// Runtime 3 ms. Beats 58.66% of users with C++
// Memory 12.8 MB. Beats 14.75% of users with C++
int findMin(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[0];
}
int main()
{
    vector<int> nums{3, 4, 5, 1, 2};
    cout<<findMin (nums)<<endl;
    return 0;
}