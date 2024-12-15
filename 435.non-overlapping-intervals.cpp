#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    return (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]));
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), cmp);
    vector<int> res(n, 1);
    int pos = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = pos; j < i; j++)
        {
            if (intervals[j][1] <= intervals[i][0])
            {
                res[i] = res[j] + 1;
                pos = i;
                break;
            }
        }
        res[i] = max(res[i - 1], res[i]);
    }

    return n - res[n - 1];
}
int main()
{
    vector<vector<int>> intervals = {{-52, 31}, {-73, -26}, {82, 97}, {-65, -11}, {-62, -49}, {95, 99}, {58, 95}, {-31, 49}, {66, 98}, {-63, 2}, {30, 47}, {-40, -26}};
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}