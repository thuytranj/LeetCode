#include <iostream>
#include <string>
using namespace std;

// Runtime 3 ms. Beats 99.35% of users with C++
// Memory 8.02 MB. Beats 85.63% of users with C++

string longestPalindrome(string s)
{
    if (s.size() <= 1)
        return s;
    if (s.size() == 2)
    {
        if (s[0] == s[1])
            return s;
        else
            return s.substr(0, 1);
    }
    int pos = 0, max = 1, left = 0, right = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (i != s.size() - 1 && s[i - 1] == s[i + 1])
        {
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if (right - left + 1 > max)
                {
                    max = right - left + 1;
                    pos = left;
                }
                left--;
                right++;
            }
        }
        if (s[i - 1] == s[i])
        {
            left = i - 1;
            right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if (right - left + 1 > max)
                {
                    max = right - left + 1;
                    pos = left;
                }
                left--;
                right++;
            }
        }
    }
    string tmp = s.substr(pos, max);
    return tmp;
}
int main()
{
    string s = "cbbd";
    cout << longestPalindrome(s) << endl;
    return 0;
}