#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Attempted
// 290 / 356 testcases passed

vector<string> findWords(string p)
{
    vector<string> words;
    int i = 0;
    while (i < p.size() && p[i] == '*')
    {
        i++;
    }
    p.erase(0, i);
    stringstream ss(p);
    string word;
    while (getline(ss, word, '*'))
    {
        words.push_back(word);
    }
    return words;
}
bool isMatch(string s, string p)
{
    vector<string> words = findWords(p);
    string cur;
    if (words.size() == 1 && words[0] == p)
    {
        if (words[0].size() != s.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (words[0][i] != '.' && words[0][i] != s[i])
                return false;
        }
        return true;
    }
    string::size_type posP = 0, posS = 0, lastposP = 0, lastposS = 0, nextposS;
    for (int i = 0; i < words.size(); i++)
    {
        posP = words[i].find_first_not_of(".", 0);
        if (posP == string::npos)
        {
            if (s.size() - lastposS < words[i].size())
                return false;
        }
        else
        {
            lastposP = words[i].find_first_of(".", posP);
            if (lastposP == string::npos)
                lastposP = words[i].size();
            cur = words[i].substr(posP, lastposP - posP);
            posS = s.find(cur, lastposS);
            if (posS == string::npos)
                return false;
            if (i == 0 && p.find(words[0]) == 0)
            {
                for (int j = 0; j < words[0].size(); j++)
                {
                    if (words[0][j] != '.' && words[0][j] != s[j])
                        return false;
                }
            }
            lastposS = posS + lastposP - posP;
            nextposS = s.find(cur, lastposS);
            if (posP != 0)
            {
                posS--;
                posP--;
                while (posP >= 0 || lastposP < words[i].size())
                {
                    if (posP >= 0)
                    {
                        if (nextposS == string::npos)
                        {
                            if (words[i][posP] != '.' && words[i][posP] != s[posS])
                                return false;
                        }
                    }
                    if (lastposP < words[i].size())
                    {
                        if (nextposS == string::npos)
                        {
                            if (words[i][lastposP] != '.' && words[i][lastposP] != s[lastposS])
                                return false;
                        }
                    }
                    if (posP > 0)
                    {
                        posP--;
                        posS--;
                    }
                    else
                        break;
                    if (lastposP < words[i].size() - 1)
                    {
                        lastposP++;
                        lastposS++;
                    }
                    else
                        break;
                }
            }
            else
            {
                for (int j = lastposP; j < words[i].size(); j++)
                {
                    if (words[i][j] != '.' && words[i][j] != '.' != s[lastposS] && nextposS == string::npos)
                        return false;
                    lastposS++;
                }
            }
        }
    }
    return true;
}

int main()
{
    string s = "aa", p = ".*";
    if (isMatch(s, p))
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}