#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check(const string &a, const string &b)
{
    if (a.size() > b.size() || (a.size() == b.size() && a != b))
        return 0;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
            i++;
        j++;
    }
    if (i < a.size())
        return 0;
    return 1;
}
bool cmp(string &a, string &b)
{
    return (a.size() > b.size() || (a.size() == b.size() && a < b));
}
string findLongestWord(string s, vector<string> &dictionary)
{
    vector<string> arr;
    for (const string &word : dictionary)
    {
        if (check(word, s))
            arr.push_back(word);
    }
    if (arr.empty())
        return "";
    sort(arr.begin(), arr.end(), cmp);
    return arr[0];
}
int main()
{
    vector<string> dictionary = {"a", "b", "c"};
    string s = "abpcplea";
    cout << findLongestWord(s, dictionary) << endl; // Output: "apple"
    return 0;
}