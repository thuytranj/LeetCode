#include <iostream>
#include <vector>
using namespace std;

// Runtime 87 ms. Beats 28.22% of users with C++
// Memory 15.98 MB. Beats 42.59% of users with C++

void findres(vector<vector<int>> &res, vector<int> &cur, vector<int> &nums, int l1, int r1, int target)
{
    int l2 = l1 + 1, r2 = r1 - 1;
    while (l2 < r2)
    {
        if ((long)nums[l1] + nums[l2] + nums[r2] + nums[r1] == target)
        {
            cur.push_back(nums[l1]);
            cur.push_back(nums[l2]);
            cur.push_back(nums[r2]);
            cur.push_back(nums[r1]);
            if (find(res.begin(), res.end(), cur) == res.end())
                res.push_back(cur);
            cur.clear();
            l2++;
        }
        else if (nums[l1] + nums[l2] + nums[r2] + nums[r1] < target)
        {
            l2++;
        }
        else
        {
            r2--;
        }
    }
}
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<int> cur;
    vector<vector<int>> res;
    if (nums.size() < 4)
        return res;
    sort(nums.begin(), nums.end());
    int l1 = 0, l2 = 1, r2 = nums.size() - 2, r1 = nums.size() - 1;
    for (l1 = 0; l1 <= nums.size() - 4; l1++)
    {
        if ((long)nums[l1] + nums[l1 + 1] + nums[l1 + 2] + nums[l1 + 3] <= target)
        {
            for (r1 = l1 + 3; r1 < nums.size(); r1++)
            {
                if (target <= (long)nums[r1 - 3] + nums[r1 - 2] + nums[r1 - 1] + nums[r1])
                {
                    findres(res, cur, nums, l1, r1, target);
                }
            }
        }
        else
            break;
    }
    return res;
}
void output(vector<vector<int>> res) {
    for (int i=0;i<res.size();i++){
        for (int j=0;j<res[i].size();j++){
            cout << res[i][j] << ' ';
        }
        cout<<endl;
    }
}
int main()
{
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    output(res);
    return 0;
}