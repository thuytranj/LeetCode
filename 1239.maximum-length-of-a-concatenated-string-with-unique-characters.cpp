#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
bool isValid(const string &s)
{
    int cnt = 0;
    set<char> cur;
    for (int i = 0; i < s.size(); i++)
    {
        cnt++;
        cur.insert(s[i]);
        if (cur.size() != cnt)
            return 0;
    }
    return 1;
}
int help(vector<string> &arr, int n)
{
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        nums[i] = i;
    }
    int res = 0;
    do
    {
        string s = "";
        for (int i = 0; i < nums.size(); i++)
        {
            s += arr[nums[i]];
        }
        if (isValid(s))
        {
            res = max(res, (int)s.size());
            cout << s << endl;
        }

        int j = n - 1;
        while (j >= 0 && nums[j] == arr.size() - n + j)
        {
            j--;
        }
        if (j < 0)
            break;
        nums[j]++;
        for (int i = j + 1; i < n; i++)
        {
            nums[i] = nums[i - 1] + 1;
        }
    } while (1);
    return res;
}
int maxLength(vector<string> &arr)
{
    int res = 0;
    for (int i = arr.size(); i >= 0; i--)
    {
        res = max (res, help(arr, i));
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, arr[i]);
    }
    cout << maxLength(arr) << endl;
    return 0;
}