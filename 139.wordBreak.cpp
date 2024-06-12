#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size();i++) {
        for (int j = 0; j < wordDict.size();j++) {
            int len = wordDict[j].size();
            if (i-len>=0 && s.substr (i-len, len)==wordDict[j] && dp[i-len])
                dp[i] = 1;
        }
    }
    return dp[s.size()];
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
        getline(cin, wordDict[i]);
    }
    if (wordBreak(s, wordDict))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}