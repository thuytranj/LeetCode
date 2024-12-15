#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), cmp);
    vector<int> dp;
    for (auto i:envelopes) {
        int h = i[1];
        auto pos = lower_bound(dp.begin(), dp.end(), h);
        if (pos==dp.end())
            dp.push_back(h);
        else *pos=h;
    }
    return dp.size();
}
int main()
{
    vector<vector<int>> envelopes = {{2, 100}, {3, 200}, {4, 300}, {5, 250}, {5, 400}, {5, 500}, {6, 360}, {6, 370}, {7, 380}};
    cout << maxEnvelopes(envelopes) << endl;
    return 0;
}