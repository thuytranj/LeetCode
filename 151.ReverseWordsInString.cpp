#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

// Runtime 7 ms. Beats 41.21% of users with C++
// Memory 9.96 MB. Beats 47.69% of users with C++

string reverseWords(string s)
{
    stack<string> cur;
    string res, word;
    stringstream ss(s);
    while (ss >> word)
    {
        cur.push(word);
    }
    while (!cur.empty())
    {
        if (cur.size() != 1)
            res += cur.top() + ' ';
        else
            res += cur.top();
        cur.pop();
    }
    return res;
}
int main()
{
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;
    return 0;
}