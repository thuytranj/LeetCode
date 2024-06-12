#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void WordBreak(string s, vector<string> &wordDict, int start, string &cur, vector<string> &res)
{
    if (start == s.size())
    {
        if (cur.size())
            cur.erase(cur.begin() + cur.size() - 1);
        res.push_back(cur);
        return;
    }
    for (int i = 0; i < wordDict.size(); i++)
    {
        int tmp = cur.size();
        cur += s.substr(start, wordDict[i].size()) + " ";
        if (s.find(wordDict[i], start) == start)
            WordBreak(s, wordDict, start + wordDict[i].size(), cur, res);
        cur.erase(tmp);
    }
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    string cur;
    vector<string> res;
    WordBreak(s, wordDict, 0, cur, res);
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    cin.ignore();
    vector<string> wordDict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wordDict[i];
    }
    vector<string> res = wordBreak(s, wordDict);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}