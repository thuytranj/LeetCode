#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    map<int, pair<int, int>> nums;
    for (int i = 0; i < intervals.size(); i++)
    {
        nums[intervals[i][0]] = {i, intervals[i][1]};
    }

    vector<int> res(intervals.size());
    for (int i = 0; i < intervals.size(); i++)
    {
        auto it = nums.lower_bound(intervals[i][1]);
        if (it == nums.end())
            res[i] = -1;
        else
            res[i] = it->second.first;
    }
    return res;
}
int main()
{
    vector<vector<int>> intervals = {{1, 4}};
    vector<int> res = findRightInterval(intervals);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}