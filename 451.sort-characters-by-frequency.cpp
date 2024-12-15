#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
string frequencySort(string s)
{
    unordered_map<char, int> fre;
    for (auto i : s)
    {
        fre[i]++;
    }
    map<int, vector<char>, greater<int>> m;
    for (auto it : fre)
    {
        m[it.second].push_back(it.first);
    }
    string res;
    for (auto it : m)
    {
        int n = it.first;
        for (auto c : it.second)
        {
            for (int i = 0; i < n; i++)
                res.push_back(c);
        }
    }
    return res;
}
int main()
{
    string s = "Aabb";
    cout << frequencySort(s) << endl;
    return 0;
}