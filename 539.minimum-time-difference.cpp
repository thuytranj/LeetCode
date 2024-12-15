#include <iostream>
#include <vector>
using namespace std;

int difference(string a, string b)
{
    int ah = stoi(a.substr(0, 2)), am = stoi(a.substr(3, 2));
    int bh = stoi(b.substr(0, 2)), bm = stoi(b.substr(3, 2));

    return (bh - ah) * 60 + bm - am;
}
int findMinDifference(vector<string> &timePoints)
{
    sort(timePoints.begin(), timePoints.end());
    int i = 0;
    int n = timePoints.size(), minDiff = difference("00:00", timePoints[0]) + difference(timePoints[n - 1], "24:00");

    while (i < n && timePoints[i] == "00:00")
    {
        timePoints.erase(timePoints.begin());
        timePoints.push_back("24:00");
    }
    for (int i = 0; i < n - 1; i++)
    {
        minDiff = min(minDiff, difference(timePoints[i], timePoints[i + 1]));
        if (minDiff == 0)
            return 0;
    }
    return minDiff;
}
int main()
{
    vector<string> timePoints = {"02:39", "10:26", "21:43"};
    cout << findMinDifference(timePoints) << endl;
    return 0;
}