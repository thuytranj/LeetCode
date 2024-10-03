#include <iostream>
#include <string>
#include <vector>

using namespace std;
void solve(string s, int &res, vector<string> &substring, int pos)
{
    if (pos == s.size())
    {
        res = max(res, (int)substring.size());
        return;
    }
    for (int i = 1; i <= s.size() - pos; i++)
    {
        string tmp = s.substr(pos, i);
        if (find(substring.begin(), substring.end(), tmp) == substring.end())
        {
            substring.push_back(tmp);
            solve(s, res, substring, pos + i);
            substring.pop_back();
        }
    }
}
int maxUniqueSplit(string s)
{
    int res = 0;
    vector<string> substring;
    solve(s, res, substring, 0);
    return res;
}
int main()
{
    string s;
    getline(cin, s);
    cout << maxUniqueSplit(s) << endl;
    return 0;
}