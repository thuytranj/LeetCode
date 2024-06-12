#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > combinate (int n, int k) {
    vector<vector<int> > res;
    vector<int> tmp(k);
    for (int i=0;i<k;i++) {
        tmp[i]=i+1;
    }
    res.push_back(tmp);
    while (1){
        int j = k - 1;
        while (j >= 0 && tmp[j] == n - k + j + 1)
        {
            j--;
        }
        if (j<0) break;
        tmp[j]++;
        for (int i = j + 1; i < k;i++) {
            tmp[i]=tmp[i-1]+1;
        }
        res.push_back(tmp);
    }
    return res;
}

vector<vector<int> > subsets(vector<int> &nums)
{
    vector<vector<int> > res;
    res.push_back(vector<int>());
    for (int i=1;i<=nums.size();i++) {
        vector<vector<int> > tmp = combinate(nums.size(), i);
        for (int j=0;j<tmp.size();j++) {
            vector<int> cur;
            for (int k=0;k<tmp[j].size();k++) {
                cur.push_back(nums[tmp[j][k] - 1]);
            }
            res.push_back(cur);
        }
    }
    return res;
}
int main (){
    vector<int> nums;
    int n;
    cin>>n;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<vector<int> > res = subsets(nums);
    if (res[0].size()==0)
        cout << "rỗng\n";
    for (int i = 1; i < res.size(); i++)
    {
        for (int j=0;j<res[i].size();j++) {
            cout << res[i][j] << ' ';
        }
        cout<<endl;
    }
    return 0;
}