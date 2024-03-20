#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Runtime 6 ms. Beats 46.02% of users with C++
// Memory 8 MB. Beats 80.46% of users with C+
bool isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size())
        return false;
    vector<vector<bool>> res(s1.size() + 1, vector<bool>(s2.size() + 1, 0));
    res[0][0] = 1;
    for (int i = 0; i <= s1.size(); i++)
    {
        for (int j = 0; j <= s2.size(); j++)
        {
            if (j >= 1 && s2[j - 1] == s3[i + j - 1] && res[i][j - 1])
                res[i][j] = 1;
            if (i >= 1 && s1[i - 1] == s3[i + j - 1] && res[i - 1][j])
                res[i][j] = 1;
        }
    }
    return res[s1.size()][s2.size()];
}
int main()
{
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    if (isInterleave(s1, s2, s3))
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}