#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Runtime 3 ms. Beats 44.68% of users with C++
// Memory 7.72 MB. Beats 52.7% of users with C++
int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;
    vector<int> res;
    res.resize(s.size() + 1);
    res[0] = 1;
    res[1] = 1;
    for (int i = 2; i <= s.size(); i++)
    {
        if (s[i - 1] == '0')
        {
            if (s[i - 2] == '1' || s[i - 2] == '2')
                res[i] = res[i - 2];
            else
                return 0;
        }

        else if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        else
            res[i] = res[i - 1];
    }
    return res[s.size()];
}
int main()
{
    string s;
    getline(cin, s);
    cout << numDecodings(s) << endl;
    return 0;
}