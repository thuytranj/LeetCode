#include <iostream>
#include <vector>
using namespace std;
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return max(nums[0], nums[1]);
    vector<bool> check(nums.size(), 0);
    vector<int> res(nums.size(), nums[0]);
    res[1] = max(nums[0], nums[1]);
    if (res[1] == nums[0])
    {
        check[0] = 1;
    }
    else
        check[1] = 1;
    for (int i = 2; i < nums.size(); i++)
    {
        if (check[i - 1])
        {
            if (nums[i] + res[i - 2] > res[i - 1])
            {
                res[i] = nums[i] + res[i - 2];
                check[i - 1] = 0;
                check[i] = 1;
            }
            else
                res[i] = res[i - 1];
        }
        else
        {
            res[i] = res[i - 1] + nums[i];
            check[i] = 1;
        }
    }
    return res[nums.size() - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << rob(a) << endl;
    return 0;
}