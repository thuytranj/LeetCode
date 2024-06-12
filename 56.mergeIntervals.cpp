#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > merge(vector<vector<int> > &intervals)
{
    sort (intervals.begin(), intervals.end());
    vector<vector<int> > res;
    res.push_back(intervals[0]);
    int i = 1;
    while (i<intervals.size()) {
        if (intervals[i][0]>res[res.size()-1][0] && intervals[i][0]<=res[res.size()-1][1]) {
            res[res.size() - 1][1] = max(intervals[i][1], res[res.size() - 1][1]);
        }
        else if (intervals[i][0]<=res[res.size()-1][0]) {
            res[res.size()-1][0]=intervals[i][0];
            res[res.size() - 1][1] = max(intervals[i][1], res[res.size() - 1][1]);
        }
        else if (intervals[i][0]>res[res.size()-1][1]) {
            res.push_back(intervals[i]);
        }
        i++;
    }
    return res;
}
int main () {
    vector<vector<int> > intervals;
    int n;
    cin >> n;
    intervals.resize(n);
    for (int i = 0; i < n;i++) {
        intervals[i].resize(2);
        cin>>intervals[i][0]>>intervals[i][1];
    }
    vector<vector<int> > res = merge(intervals);
    for (int i = 0; i < res.size();i++) {
        for (int j = 0; j < res[i].size();j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}