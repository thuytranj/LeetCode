#include <iostream>
#include <vector>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 7.31 MB. Beats 11.09% of users with C++
int climbStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    vector<int> res(n, 1);
    res[1] = 2;
    for (int i = 2; i < n; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res[n - 1];
}
int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}