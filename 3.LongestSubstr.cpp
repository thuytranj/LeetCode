#include <iostream>
#include <string>
#include <set>
using namespace std;

// Runtime 600 ms. Beats 5.35% of users with C++
// Memory 266.27 MB. Beats 5.03% of users with C++

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
        return 0;
    set<char> substr;
    int max = 1, count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        substr.clear();
        substr.insert(s[i]);
        count = 1;
        for (int j = i + 1; j < s.size(); j++)
        {
            substr.insert(s[j]);
            count++;
            if (substr.size() != count || j == s.size() - 1)
            {
                if (substr.size() > max)
                {
                    max = substr.size();
                }
                break;
            }
        }
    }
    return max;
}

int main()
{
    string s = "bbbbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}