#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool find132pattern(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;
    map<int, int> s;
    s[nums[0]] = 0;
    s[nums[1]] = 1;

    for (int i = 2; i < n; i++)
    {
        auto it = s.upper_bound(nums[i]);

        if (it != s.end() && it != s.begin() && s.begin()->first < nums[i])
        {
            auto minPos = s.begin(), maxPos = it;
            int res1 = minPos->second, res2 = maxPos->second;

            while (minPos != it && maxPos != s.end() && minPos->first < nums[i])
            {
                res1 = min(res1, minPos->second);
                res2 = max(res2, maxPos->second);
                if (res1 < res2)
                    return 1;
                minPos++;
                maxPos++;
            }

            while (minPos != it && minPos->first < nums[i])
            {
                res1 = min(res1, minPos->second);
                if (res1 < res2)
                    return 1;
                minPos++;
            }

            while (maxPos != s.end())
            {
                res2 = max(res2, maxPos->second);
                if (res1 < res2)
                    return 1;
                maxPos++;
            }
        }

        if (s.find(nums[i]) == s.end())
            s[nums[i]] = i;
    }

    return 0;
}
int main()
{
    vector<int> nums = {-1, 3, 2, 0};
    cout << (find132pattern(nums) ? "Yes" : "No") << endl;
    return 0;
}