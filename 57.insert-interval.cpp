#include <iostream>
#include <vector>
using namespace std;
void findIndex (vector<vector<int> >intervals, vector<int> newInterval, int& pos1, int& pos2) {
    if (newInterval[0]>intervals[intervals.size()-1][1]) {
        pos1 = pos2 = intervals.size();
        return;
    }
    if (newInterval[1]<intervals[0][0]) {
        return;
    }
    int i=0;
    while (i<intervals.size()) {
        if (pos1==-1 && ((newInterval[0]>=intervals[i][0] && newInterval[0]<=intervals[i][1]) || newInterval[0]<intervals[i][0] )){
            pos1=i;
        }
        if ((newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) || (i + 1 < intervals.size() && newInterval[1] < intervals[i + 1][0])){
            pos2=i;
            if (pos1!=-1) return;
        }
        i++;
    }
    if (pos2==-1)
        pos2 = intervals.size();
}
vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval)
{
    if (newInterval.size()==0) return intervals;
    vector<vector<int> > res;
    if (intervals.size() == 0) {
        res.push_back(newInterval);
        return res;
    }
    int pos1=-1, pos2=-1;
    findIndex(intervals, newInterval, pos1, pos2);

    cout<<pos1<<' '<<pos2<<endl;
    if (pos2==-1 || pos1==intervals.size()) {
        res = intervals;
        if (pos2==-1)
            res.insert(res.begin(), newInterval);
        else
            res.push_back(newInterval);
        return res;
    }
        for (int i=0;i<pos1;i++) {
            res.push_back(intervals[i]);
        }
        vector<int> tmp(2);
        tmp[0] = (pos1 == -1) ? newInterval[0] : min(newInterval[0], intervals[pos1][0]);
        if (pos2==intervals.size()) {
            tmp[1] = newInterval[1];
        }
        else {
            if (newInterval[1]<intervals[pos2][0]) {
                tmp[1] = newInterval[1];
            }
            else {
                tmp[1] = max (newInterval[1], intervals[pos2][1]);
                pos2++;
            }
        }
        //tmp[1] = (pos2 == intervals.size()) ? newInterval[1] : max(newInterval[1], intervals[pos2][1]);
        res.push_back(tmp);

        for (int i=pos2;i<intervals.size();i++) {
            res.push_back(intervals[i]);
        }
        return res;
}
int main () {
    int n;
    cin >> n;
    vector<vector<int> > intervals(n);
    for (int i=0;i<n;i++) {
        intervals[i].resize(2);
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];
    vector<vector<int> > res = insert(intervals, newInterval);
    for (int i=0;i<res.size();i++) {
        cout<<res[i][0]<<' '<<res[i][1]<<endl;
    }
    return 0;
}
