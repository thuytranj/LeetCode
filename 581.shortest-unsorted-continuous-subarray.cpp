#include <iostream>
#include <vector>
using namespace std;
int findUnsortedSubarray(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1, n = nums.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i <= r; i++)
    {
        arr.push_back({nums[i], i});
    }
    sort(arr.begin(), arr.end());
    while (l <= r && arr[l].second == l && arr[r].second == r)
    {
        l++;
        r--;
    }

    while (l<=r && arr[l].second == l) {
        l++;
    }

    while (l<=r && arr[r].second==r)
        r--;
    cout << arr[l].first << " " << arr[l].second << endl;
    cout << arr[r].first << " " << arr[r].second << endl;
    if (l < r)
        return r - l + 1;
    return 0;
}
int main()
{
    vector<int> nums = {1, 3, 2, 4, 5};
    cout << findUnsortedSubarray(nums) << endl;
    return 0;
}