#include <iostream>
#include <string>
#include <vector>
using namespace std;

// attempted
// 169 / 179 testcases passed. Runtime error!

bool isTrueWord(string s, int start, vector<string> words, int n, bool isAppear[])
{
    for (int i = 0; i < n; i++)
    {
        if (words[i][0] == s[start] && isAppear[i] == false)
        {
            bool full = true;
            for (int j = 1; j < words[i].size(); j++)
            {
                if (words[i][j] != s[start + j])
                {
                    full = false;
                    break;
                }
            }
            if (full)
            {
                isAppear[i] = true;
                return true;
            }
        }
    }
    return false;
}
vector<int> findSubstring(string s, vector<string> &words)
{
    int count, n = words.size();
    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
    {
        if ((i + words[0].size() * n - 1) < s.size())
        {
            bool isAppear[100] = {};
            count = 0;
            for (int j = i; j < i + words[0].size() * n; j += words[0].size())
            {
                if (isTrueWord(s, j, words, n, isAppear))
                {
                    count++;
                }
                else
                    break;
            }
            if (count == n)
                pos.emplace_back(i);
        }
    }
    return pos;
}
void output (vector<int> res){
    for (int i=0;i<res.size();i++){
        cout << res[i] << ' ';
    }
    cout<<endl;
}
int main()
{
    string s = "barfoofoobarthefoobarman";
    vector<string> words{"bar", "foo", "the"};
    vector<int> res = findSubstring(s, words);
    output(res);
    return 0;
}