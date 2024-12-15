#include <iostream>
#include <vector>
using namespace std;
int minMoves2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), mid = nums[n / 2], sum = 0;
    for (int i : nums)
    {
        if (i != mid)
            sum += abs(i - mid);
    }
    return sum;
}
int main()
{
    vector<int> nums = {1, 10, 2, 9};
    cout << minMoves2(nums) << endl;
    return 0;
}