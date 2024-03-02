#include <iostream>
#include <vector>
using namespace std;

// Runtime 337 ms. Beats 7.69% of users with C++
// Memory 10.79 MB. Beats 86.45% of users with C++

vector<int> twoSum(vector<int> &nums, int target)
{
    int cur, cur2;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cur = i;
                cur2 = j;
                break;
            }
        }
    }
    return {cur, cur2};
}

void output(vector<int> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
}
int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    output(res);
    return 0;
}