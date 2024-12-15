#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    return (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]));
}
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), cmp);
    for (auto i : points)
        cout << i[0] << ' ' << i[1] << endl;
    vector<vector<int>> res;
    res.push_back(vector<int>{points[0][0], points[0][1]});
    for (int i = 1; i < points.size(); i++)
    {
        int j = res.size() - 1;
        while (j >= 0 && res[j][1] < points[i][0])
            j--;
        if (j >= 0)
        {
            res[j][0] = points[i][0];
            res[j][1] = min(res[j][1], points[i][1]);
        }
        else
            res.push_back(points[i]);
    }
    for (auto i : res)
        cout << i[0] << ' ' << i[1] << endl;
    return res.size();
}
int main()
{
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << findMinArrowShots(points) << endl;
    return 0;
}