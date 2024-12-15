#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.first.size() > b.first.size();
}
bool check(const string &a, const string &b)
{
    if (a.size() > b.size() || (a.size() == b.size() && a != b))
        return 0;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
            i++;
        j++;
    }
    if (i < a.size())
        return 0;
    return 1;
}
int findLUSlength(vector<string> &strs)
{
    unordered_map<string, int> m;
    for (const string &str : strs)
    {
        m[str]++;
    }
    vector<pair<string, int>> arr;
    for (auto i : m)
    {
        arr.push_back({i.first, i.second});
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].second == 1)
        {
            bool fl = 1;
            for (int j = 0; j < i; j++)
            {
                if (check(arr[i].first, arr[j].first))
                {
                    fl = 0;
                    break;
                }
            }
            if (fl)
                return arr[i].first.size();
        }
    }
    return -1;
}
int main()
{
    vector<string> strs = {"aaa", "aaa", "aa"};
    cout << findLUSlength(strs) << endl; // Output: 3
    return 0;
}