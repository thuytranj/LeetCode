#include <iostream>
#include <vector>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    if (nums.size()==0)
        return 0;
    sort(nums.begin(), nums.end());
    int Max=1, tmp=1;
    for (int i=1;i<nums.size();i++) {
        if (nums[i]-nums[i-1]==1)
            tmp++;
        else if (nums[i]-nums[i-1]>1) {
            Max = max(tmp, Max);
            tmp=1;
        }
    }
    return max(Max, tmp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << longestConsecutive(nums) << endl;
    return 0;
}