#include <iostream>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 7.27 MB. Beats 43.66% of users with C++

int firstBadVersion(int n)
{
    int l = 1, r = n, min = n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (isBadVersion(m))
        {
            if (m < min)
                min = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return min;
}
int main()
{
    return 0;
}