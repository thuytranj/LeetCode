#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> thapPhan(string s)
{
    vector<string> res;
    if (s.size() == 2 && s[0] == '0' && s[1] == '0')
    {
        return res;
    }
    for (int i = 1; i < s.size(); i++)
    {
        string cur = s;
        string tmp = s.substr(0, i);
        string tmp2 = s.substr(i, s.size() - i);
        if ((stoi(tmp) >= pow(10, i - 1) || tmp == "0") && stoi(tmp2) != 0 && tmp2[tmp2.size() - 1] != '0')
            res.push_back(cur.insert(i, "."));
    }
    if (stoi(s) >= pow(10, s.size() - 1) || s == "0")
        res.push_back(s);
    return res;
}
vector<string> ambiguousCoordinates(string s)
{
    vector<string> res;
    for (int i = 2; i < s.size() - 1; i++)
    {
        string cur = s.substr(1, i - 1);
        string cur2 = s.substr(i, s.size() - i - 1);
        vector<string> temp = thapPhan(cur);
        vector<string> temp2 = thapPhan(cur2);
        for (int j = 0; j < temp.size(); j++)
        {
            for (int k = 0; k < temp2.size(); k++)
            {
                string cur3 = "(" + temp[j];
                cur3 += ",";
                cur3 += temp2[k] + ")";
                res.push_back(cur3);
            }
        }
    }
    return res;
}
int main()
{
    string s;
    getline(cin, s);
    vector<string> res = ambiguousCoordinates(s);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}