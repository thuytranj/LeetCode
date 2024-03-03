#include <iostream>
#include <vector>
using namespace std;

// Runtime 11 ms. Beats 79.81% of users with C++
// Memory 20.91 MB. Beats 41.36% of users with C++

int hIndex(vector<int> &citations)
{
    int start = 0, end = citations.size() - 1, max = 0;
    while (start <= end)
    {
        int m = (start + end) / 2;
        if (citations.size() - m <= citations[m])
        {
            if (citations.size() - m > max)
                max = citations.size() - m;
            end = m - 1;
        }
        else
            start = m + 1;
    }
    return max;
}
int main()
{
    vector<int> citations{0, 1, 3, 5, 6};
    cout<<hIndex(citations)<<endl;
    return 0;
}