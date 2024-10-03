#include <iostream>
#include <string>
#include <vector>
using namespace std;
string addOne(string a)
{
    string res = a;
    int mem = 1;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int temp = (res[i] - '0') + mem;
        res[i] = temp % 10 + '0';
        mem = temp / 10;
    }
    if (mem != 0)
        res.insert(res.begin(), mem + '0');
    return res;
}
bool isValid(string a, string b)
{
    return addOne(a) == b;
}
bool solve(string s, vector<string> nums, int pos)
{
    if (nums.size() > 1 && !isValid(nums.back(), nums[nums.size() - 2]))
        return 0;
    if (pos == s.size())
        return 1;
    for (int i = 1; i <= nums.size() - pos; i++)
    {
        nums.push_back(s.substr(pos, i));
        if (solve(s, nums, pos + i))
            return 1;
        nums.pop_back();
    }
    return 0;
}
bool splitString(string s)
{
    vector<string> nums;
    if (solve(s, nums, 0))
        return 1;
    return 0;
}
int main()
{
    string s;
    getline(cin, s);
    if (splitString(s))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}