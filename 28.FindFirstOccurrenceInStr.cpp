#include <iostream>
#include <string>
using namespace std;

// Runtime 3 ms. Beats 42.75% of users with C++
// Memory 7.59 MB. Beats 38.59% of users with C++

int strStr(string haystack, string needle)
{
    string::size_type pos = haystack.find(needle);
    if (pos != string::npos)
        return pos;
    return -1;
}
int main()
{
    string haystack = "leetcode", needle = "leeto";
    cout<<strStr (haystack, needle)<<endl;
    return 0;
}