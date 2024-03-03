#include <iostream>
#include <vector>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 7.5 MB. Beats 28.77% of users with C++

int mySqrt(int x)
{
    int l = 0, r = 46340;
    if (46340 * 46340 < x)
        return r;
    if (x == 0)
        return l;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if ((long)m * m <= x && (long)(m + 1) * (m + 1) > x)
            return m;
        else
        {
            if (m * m > x)
                r = m - 1;
            else
                l = m + 1;
        }
    }
    return -1;
}
int main()
{
    int x =8;
    cout<<mySqrt (x)<<endl;
    return 0;
}