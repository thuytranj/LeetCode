#include <iostream>
#include <string>
using namespace std;

// Runtime 7 ms. Beats 76.07% of users with C++
// Memory 9.64 MB. Beats 58.21% of users with C++

int romanToInt(string s)
{
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'M')
            num += 1000;
        else if (i + 1 < s.size() && s[i] == 'C' && s[i + 1] == 'M')
        {
            num += 900;
            i++;
        }
        else if (i + 1 < s.size() && s[i] == 'C' && s[i + 1] == 'D')
        {
            num += 400;
            i++;
        }
        else if (s[i] == 'C')
            num += 100;
        else if (s[i] == 'D')
            num += 500;
        else if (i + 1 < s.size() && s[i] == 'X' && s[i + 1] == 'C')
        {
            num += 90;
            i++;
        }
        else if (i + 1 < s.size() && s[i] == 'X' && s[i + 1] == 'L')
        {
            num += 40;
            i++;
        }
        else if (s[i] == 'X')
            num += 10;
        else if (s[i] == 'L')
            num += 50;
        else if (i + 1 < s.size() && s[i] == 'I' && s[i + 1] == 'X')
        {
            num += 9;
            i++;
        }
        else if (i + 1 < s.size() && s[i] == 'I' && s[i + 1] == 'V')
        {
            num += 4;
            i++;
        }
        else if (s[i] == 'I')
            num += 1;
        else
            num += 5;
    }
    return num;
}
int main()
{
    string s = "MCMXCIV";
    cout << romanToInt(s) << endl;
    return 0;
}