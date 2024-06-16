#include <iostream>
#include <vector>
#include <set>
using namespace std;
int sum (vector<int> nums) {
    int sum=0;
    for (int i = 0;i<nums.size();i++) {
        sum += nums[i];
    }
    return sum;
}
void solve (vector<vector<int> > &res, int start, vector<int> &cur, int k, int n) {
    if (cur.size()==k) {
        if (sum(cur)==n) {
            res.push_back(cur);
            return;
        }
    }
    for (int i = start; i < 10;i++) {
            cur.push_back(i);
            solve(res, i+1, cur, k, n);
            cur.pop_back();
    }
}
vector<vector<int> > combinationSum3(int k, int n)
{
    vector<vector<int> > res;
    vector<int> cur;
    solve(res, 1, cur, k, n);
    return res;
}
int main () {
    int k, n;
    cin>>k>>n;
    vector<vector<int> > res = combinationSum3(k, n);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}