#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve(string s, vector<string> &res, string &cur)
{
    if (cur.size() == s.size())
    {
        res.push_back(cur);
        return;
    }
    if (s[cur.size()]<48 || s[cur.size()]>57) {

        cur += tolower(s[cur.size()]);
        solve(s, res, cur);
        cur.pop_back();

        cur += toupper(s[cur.size()]);
        solve(s, res, cur);
        cur.pop_back();
    }
    else {
        cur += s[cur.size()];
        solve(s, res, cur);
        cur.pop_back();
    }
}
vector<string> letterCasePermutation(string s)
{
    vector<string> res;
    string cur = "";
    solve(s, res, cur);
    return res;
}
int main()
{
    string s;
    getline(cin, s);
    vector<string> res = letterCasePermutation(s);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}