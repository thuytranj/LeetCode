#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve(vector<string> &nums, string &res, string &cur, int pos)
{
    if (pos == nums[0].size())
    {
        if (find(nums.begin(), nums.end(), cur) == nums.end())
            res = cur;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        cur.push_back(i + '0');
        solve(nums, res, cur, pos + 1);
        if (!res.empty())
            return;
        cur.pop_back();
    }
}
string findDifferentBinaryString(vector<string> &nums)
{
    string res, cur;
    solve(nums, res, cur, 0);
    return res;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, nums[i]);
    }
    cout << findDifferentBinaryString(nums) << endl;
    return 0;
}