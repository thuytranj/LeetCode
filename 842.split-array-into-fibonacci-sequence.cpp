#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve(string num, vector<int> &res, vector<int> &cur, string &tmp)
{
    if (cur.size() > 2)
    {
        long long last = static_cast<long long>(cur[cur.size() - 1]);
        long long second_last = static_cast<long long>(cur[cur.size() - 2]);
        long long third_last = static_cast<long long>(cur[cur.size() - 3]);
        if (last != second_last + third_last)
        {
            return;
        }
    }
    if (tmp.size() == num.size())
    {
        res = cur;
        return;
    }
    for (int i = tmp.size(); i < num.size(); i++)
    {
        string cur1 = num.substr(tmp.size(), i - tmp.size() + 1);
        if (cur1.size() > 1 && cur1[0] == '0')
            break; // avoid numbers with leading zeros
        long long tmp1 = stoll(cur1);
        if (tmp1 > INT_MAX)
            break; // avoid numbers greater than INT_MAX
        cur.push_back(static_cast<int>(tmp1));
        tmp += cur1;
        solve(num, res, cur, tmp);
        cur.pop_back();
        tmp.erase(tmp.size() - cur1.size(), cur1.size());
        if (!res.empty())
            return; // early termination if solution found
    }
}

vector<int> splitIntoFibonacci(string num)
{
    vector<int> res;
    for (int i = 0; i < num.size() - 2; i++)
    {
        string cur1 = num.substr(0, i + 1);
        if (cur1.size() > 1 && cur1[0] == '0')
            break; // avoid numbers with leading zeros
        long long num1 = stoll(cur1);
        if (num1 > INT_MAX)
            break; // avoid numbers greater than INT_MAX
        vector<int> cur;
        cur.push_back(static_cast<int>(num1));
        for (int j = i + 1; j < num.size() - 1; j++)
        {
            string cur2 = num.substr(i + 1, j - i);
            if (cur2.size() > 1 && cur2[0] == '0')
                break; // avoid numbers with leading zeros
            long long tmp2 = stoll(cur2);
            if (tmp2 > INT_MAX)
                break; // avoid numbers greater than INT_MAX
            cur.push_back(static_cast<int>(tmp2));
            string tmp = cur1 + cur2;
            solve(num, res, cur, tmp);
            if (!res.empty())
                return res; // early termination if solution found
            cur.pop_back();
        }
    }
    return res;
}
int main()
{
    string num;
    getline(cin, num);
    vector<int> res = splitIntoFibonacci(num);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}