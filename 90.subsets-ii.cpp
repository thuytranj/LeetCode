#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int> > combinate (int n, int k, vector<int> nums) {
    vector<vector<int> > res;
    int cnt=0;
    vector<int> tmp;
    for (int i=0;i<k;i++) {
        tmp.push_back(i);
    }
    while (1) {
        vector<int> cur;
        for (int i=0;i<k;i++) {
            cout << tmp[i] << ' ';
            cur.push_back(nums[tmp[i]]);
        }
        cout<<endl;
        res.push_back(cur);
        int j = k - 1;
        while (j>=0 && tmp[j]==n-k+j) {
            j--;
        }
        if (j<0) break;
        tmp[j]++;
        for (int i=j+1;i<tmp.size();i++) {
            tmp[i]=tmp[i-1]+1;
        }
    }
    return res;
}
vector<vector<int> > subsetsWithDup(vector<int> &nums)
{
    set<vector<int> > cur;
    vector<vector<int> > res;
    res.push_back(vector<int>());
    for (int i=1;i<=nums.size();i++) {
        vector<vector<int> > tmp = combinate(nums.size(), i, nums);
        for (int j=0;j<tmp.size();j++) {
            sort(tmp[j].begin(), tmp[j].end());
            if (cur.find(tmp[j]) == cur.end())
            {
                cur.insert(tmp[j]);
                res.push_back(tmp[j]);
            }
        }
    }
    return res;
}
int main () {
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }
    vector<vector<int> > res = subsetsWithDup(nums);
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size();j++) {
            cout << res[i][j] << ' ';
        }
        cout<<endl;
    }
    return 0;
}