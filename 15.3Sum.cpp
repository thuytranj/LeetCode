#include <iostream>
#include <vector>
using namespace std;

// Runtime 167 ms. Beats 43.78% of users with C++
// Memory 24.4 MB. Beats 90.91% of users with C++

vector<vector<int>> threeSum(vector<int> &nums)
{
    int j, k;
    vector<int> v;
    vector<vector<int>> t;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        else
        {
            j = i + 1;
            k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    v.emplace_back(nums[i]);
                    v.emplace_back(nums[j]);
                    v.emplace_back(nums[k]);
                    t.emplace_back(v);
                    v.clear();
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                    j++;
            }
        }
    }
    return t;
}
void output(vector<vector<int>> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    output(res);
    return 0;
}