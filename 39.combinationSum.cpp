#include <iostream>
#include <vector>
#include <set>
using namespace std;
void combination(vector<int> &candidates, int target, int start, vector<int> &nums, vector<vector<int> > &res)
{
    if (target == 0)
    {
        res.push_back(nums);
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        if (candidates[i] > target)
            break;
        nums.push_back(candidates[i]);
        combination(candidates, target - candidates[i], i, nums, res);
        nums.pop_back();
    }
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > res;
    vector<int> nums;
    combination(candidates, target, 0, nums, res);
    return res;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }
    cin >> target;
    vector<vector<int> > res = combinationSum(candidates, target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}