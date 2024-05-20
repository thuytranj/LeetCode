#include <iostream>
#include <vector>
using namespace std;
void permutation (vector<int> &nums, vector<bool> &used, vector<int> &cur, vector<vector<int> > &res){
    if (cur.size()==nums.size()) {
        res.push_back(cur);
        return;
    }
    for (int i = 0; i < nums.size();i++){
        if (used[i]) continue;
        if (i>0 && nums[i]==nums[i-1] && !used[i-1]) continue; //skip duplicate
        used[i] = true;
        cur.push_back(nums[i]);
        permutation(nums, used, cur,res);
        cur.pop_back();
        used[i] = false;
    }
}
vector<vector<int> > permuteUnique(vector<int> &nums)
{
    sort (nums.begin(),nums.end());
    vector<int> cur;
    vector<vector<int> > res;
    vector<bool> used(nums.size(),false);
    permutation(nums, used, cur,res);
    return res;
}
int main (){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int> > res = permuteUnique(a);
    for (int i = 0;i<res.size();i++){
        for (int j = 0; j < res[i].size();j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}