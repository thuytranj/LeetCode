#include <iostream>
#include <vector>
using namespace std;
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<pair<int, int>> res(n, {1, -1});
    int maxLen = 1, index = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        while (j >= 0)
        {
            if (nums[i] % nums[j] == 0)
            {
                if (res[i].first < res[j].first + 1)
                {
                    res[i].first = res[j].first + 1;
                    if (res[i].first > maxLen)
                    {
                        maxLen = res[i].first;
                        index = i;
                    }
                    res[i].second = j;
                }
            }
            j--;
        }
    }

    vector<int> ans;
    cout << nums[index] << endl;
    ans.push_back(nums[index]);
    while (res[index].second >= 0)
    {
        ans.push_back(nums[res[index].second]);
        index = res[index].second;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 4, 8};
    vector<int> res = largestDivisibleSubset(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}