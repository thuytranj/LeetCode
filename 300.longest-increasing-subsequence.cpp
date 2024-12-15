#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int binarySearch(vector<int> &nums, int x)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == x)
            return mid;
        else if (nums[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> arr;
    for (int i : nums)
    {
        if (arr.empty() || i > arr.back())
        {
            arr.push_back(i);
        }
        else
        {
            int pos = binarySearch(arr, i);
            arr[pos] = i;
        }
    }
    return arr.size();
}
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}