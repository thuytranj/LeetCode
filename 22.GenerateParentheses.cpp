#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// Runtime 6 ms. Beats 24.39% of users with C++
// Memory 10.16 MB. Beats 97.11% of users with C++
vector<string> generateParenthesis(int n)
{
    if (n == 0)
        return vector<string>();
    vector<set<string>> arr;
    arr.resize(n);
    arr[0].insert("()");
    for (int i = 1; i < n; i++)
    {
        for (auto it = arr[i - 1].begin(); it != arr[i - 1].end(); it++)
        {
            for (int k = 0; k < (*it).size(); k++)
            {
                string cur = *it;
                arr[i].insert(cur.insert(k, "()"));
            }
        }
    }
    vector<string> res;
    for (auto it = arr[n - 1].begin(); it != arr[n - 1].end(); it++)
    {
        res.push_back(*it);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<string> res = generateParenthesis(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}