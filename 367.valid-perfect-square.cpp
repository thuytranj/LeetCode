#include <iostream>
using namespace std;
bool isPerfectSquare(int num)
{
    long long l = 1, r = num;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        if (m * m == num)
            return 1;
        else if (m * m < num)
            l = m + 1;
        else
            r = m - 1;
    }
    return 0;
}
int main()
{
    if (isPerfectSquare(20))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}