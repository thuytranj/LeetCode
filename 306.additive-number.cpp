#include <iostream>
#include <string>
using namespace std;
bool isValid(string num)
{
    if (num.size() > 1 && num[0] == '0')
        return 0;
    return 1;
}
void solve(string num, int pos1, int size1, int pos2, int size2, int pos3, int size3, bool &res)
{
    if (size1 == 0 || size2 == 0 || size3 == 0)
        return;

    string first = num.substr(pos1, size1);
    if (!isValid(first))
        return;
    string second = num.substr(pos2, size2);
    if (!isValid(second))
        return;
    string third = num.substr(pos3, size3);
    if (!isValid(third))
        return;

    if (to_string(stoll(first) + stoll(second)) != third)
        return;
    else
    {
        if (pos3 + size3 == num.size())
        {
            res = 1;
            return;
        }
        for (int i = pos3 + size3; i < num.size(); i++)
        {
            solve(num, pos2, size2, pos3, size3, pos3 + size3, i - pos3 - size3 + 1, res);
            if (res)
                return;
        }
    }
}
bool isAdditiveNumber(string num)
{
    if (num.size() < 3)
        return 0;
    bool res = 0;
    for (int i = 0; i < num.size() - 2; i++)
    {
        for (int j = i + 1; j < num.size() - 1; j++)
        {
            for (int k = j + 1; k < num.size(); k++)
            {
                solve(num, 0, i + 1, i + 1, j - i, j + 1, k - j, res);
                if (res)
                    break;
            }
            if (res)
                break;
        }
        if (res)
            break;
    }
    return res;
}
int main()
{
    string num;
    getline(cin, num);
    if (isAdditiveNumber(num))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}