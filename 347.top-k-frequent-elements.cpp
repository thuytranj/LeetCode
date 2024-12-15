#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> m;
    for (int i : nums)
        m[i]++;
    if (k>m.size()) return vector<int>();
    vector<pair<int, int>> f;
    for (const auto &pair : m)
        f.push_back({pair.first, pair.second});
    sort(f.begin(), f.end(), cmp);
    vector<int> result;
    for (int i = 0; i < k; i++)
        result.push_back(f[i].first);
    return result;
}
int main()
{
    vector<int> nums = {1};
    int k = 1;
    vector<int> res = topKFrequent(nums, k);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}