#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
bool isValid(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}
int minCut(string s)
{
    if (s.size()<=1)
       return 0;
    vector<int> res (s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        set<int> cur;
        for (int j = 0; j < i; j++)
        {
            if (isValid(s, j, i))
            {
                if (j>0) cur.insert(res[j-1]+1);
                else cur.insert(0);
            }
        }
        if (cur.size()==0) {
            res[i] = res[i - 1] + 1;
        }
        else
            res[i] = min (*cur.begin(), res[i-1]+1);
    }
    for (int i = 0; i < res.size();i++)
        cout << res[i] << ' ';
    cout << endl;
    return res[res.size() - 1];
}
int main()
{
    string s;
    getline(cin, s);
    cout << minCut(s) << endl;
    return 0;
}