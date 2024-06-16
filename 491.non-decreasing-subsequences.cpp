#include <iostream>
#include <vector>
#include <set>
using namespace std;
void solve (vector<int> nums, set<vector<int> >  &res, vector<int> &cur, int index) {
    if (cur.size()>1) {
        res.insert(cur);
    }
    for (int i = index; i < nums.size(); i++)
    {
        if (cur.empty() || nums[i]>=cur.back()) {
            cur.push_back(nums[i]);
            solve(nums, res, cur, i+1);
            cur.pop_back();
        }
    }
}
vector<vector<int> > findSubsequences(vector<int> &nums)
{
    if (nums.size()<2)
        return vector<vector<int> >();

    vector<int> cur;
    set<vector<int> > tmp;
    solve(nums, tmp, cur, 0);
    return vector<vector<int> > (tmp.begin(), tmp.end());
}
int main () {
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    vector<vector<int> > res = findSubsequences(nums);

    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}