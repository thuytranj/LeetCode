#include <iostream>
#include <vector>
using namespace std;
int jump(vector<int> &nums)
{
    vector<int> res(nums.size(), INT_MAX);
    res[0] = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j <= i + nums[i]; j++)
        {
            if (j>=nums.size())
                break;
            res[j] = min(res[i] + 1, res[j]);
        }
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
    return res[res.size() - 1];
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
    cout << jump(nums) << endl;
    return 0;
}