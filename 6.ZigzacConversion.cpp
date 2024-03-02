#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Runtime 11 ms. Beats 55.27% of users with C++
// Memory 10.53 MB. Beats 77.68% of users with C++

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    string tmp;
    int i = 0;
    vector<int> pos;
    while (i * (2 * (numRows - 2) + 2) < s.size())
    {
        tmp += s[i * (2 * (numRows - 2) + 2)];
        pos.push_back(i * (2 * (numRows - 2) + 2));
        i++;
    }
    pos.push_back(i * (2 * (numRows - 2) + 2));
    for (i = 1; i < numRows; i++)
    {
        for (int j = 0; j < pos.size(); j++)
        {
            if (pos[j] - i >= 0 && pos[j] - i < s.size() && i != numRows - 1)
                tmp += s[pos[j] - i];
            if (pos[j] + i >= 0 && pos[j] + i < s.size())
                tmp += s[pos[j] + i];
        }
    }
    return tmp;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string res = convert(s, numRows);
    cout << res << endl;
    return 0;
}