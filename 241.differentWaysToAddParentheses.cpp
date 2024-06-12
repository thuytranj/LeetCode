#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> diffWaysToCompute(string expression)
{
    size_t found = expression.find_first_of("+-*/");
    if (found == string::npos)
    {
        vector<int> res(1, stoi(expression));
        return res;
    }
    vector<int> res;
    while (found != string::npos)
    {
        vector<int> left = diffWaysToCompute(expression.substr(0, found));
        vector<int> right = diffWaysToCompute(expression.substr(found + 1));
        for (int i = 0; i < left.size(); i++)
        {
            for (int j = 0; j < right.size(); j++)
            {
                if (expression[found] == '+')
                {
                    res.push_back(left[i] + right[j]);
                }
                else if (expression[found] == '-')
                {
                    res.push_back(left[i] - right[j]);
                }
                else if (expression[found] == '*')
                {
                    res.push_back(left[i] * right[j]);
                }
                else if (expression[found] == '/')
                {
                    res.push_back(left[i] / right[j]);
                }
            }
        }
        found = expression.find_first_of("+-*/", found + 1);
    }
    return res;
}
int main()
{
    string expression;
    getline(cin, expression);
    vector<int> result = diffWaysToCompute(expression);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}