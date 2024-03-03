#include <iostream>
#include <string>
#include <map>
using namespace std;

// Runtime 15 ms. Beats 10.74% of users with C++
// Memory 9.76 MB. Beats 13.2% of users with C++
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    map<char, int> str1, str2;
    int i = 0;
    map<char, int>::iterator it1, it2;
    while (i < s.size() && i < t.size())
    {
        it1 = str1.find(s[i]);
        it2 = str2.find(t[i]);
        if (it1 == str1.end())
        {
            str1.insert(pair<char, int>(s[i], 1));
        }
        else
        {
            str1[s[i]]++;
        }
        if (it2 == str2.end())
        {
            str2.insert(pair<char, int>(t[i], 1));
        }
        else
        {
            str2[t[i]]++;
        }
        i++;
    }
    it1 = str1.begin(), it2 = str2.begin();
    while (it1 != str1.end() && it2 != str2.end())
    {
        if (it1->first != it2->first)
            return false;
        else
        {
            if (it1->second != it2->second)
                return false;
        }
        it1++;
        it2++;
    }
    return true;
}
int main()
{
    string s = "anagram", t = "nagaram";
    if (isAnagram (s, t))
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}