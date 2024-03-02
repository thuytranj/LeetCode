#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Runtime 13 ms. Beats 17.78% of users with C++
// Memory 12.75 MB. Beats 28.45% of users with C++

string readHundred(int num)
{
    string cur;
    int hundred = num / 100;
    int unit = num % 10;
    int ten = (num - hundred * 100 - unit) / 10;
    if (hundred != 0)
    {
        if (hundred == 1)
            cur += 'C';
        else if (hundred == 5)
            cur += 'D';
        else if (hundred == 4)
            cur += "CD";
        else if (hundred == 9)
            cur += "CM";
        else if (hundred > 1 && hundred < 4)
        {
            for (int i = 0; i < hundred; i++)
            {
                cur += 'C';
            }
        }
        else
        {
            cur += 'D';
            for (int i = 5; i < hundred; i++)
            {
                cur += 'C';
            }
        }
    }
    if (ten != 0)
    {
        if (ten == 1)
            cur += 'X';
        else if (ten == 5)
            cur += 'L';
        else if (ten == 4)
            cur += "XL";
        else if (ten == 9)
            cur += "XC";
        else if (ten > 1 && ten < 4)
        {
            for (int i = 0; i < ten; i++)
            {
                cur += 'X';
            }
        }
        else
        {
            cur += 'L';
            for (int i = 5; i < ten; i++)
            {
                cur += 'X';
            }
        }
    }
    if (unit != 0)
    {
        if (unit == 1)
            cur += 'I';
        else if (unit == 5)
            cur += 'V';
        else if (unit == 4)
            cur += "IV";
        else if (unit == 9)
            cur += "IX";
        else if (unit > 1 && unit < 4)
        {
            for (int i = 0; i < unit; i++)
            {
                cur += 'I';
            }
        }
        else
        {
            cur += 'V';
            for (int i = 5; i < unit; i++)
            {
                cur += 'I';
            }
        }
    }
    return cur;
}
string intToRoman(int num)
{
    string cur;
    stack<int> nums;
    while (num > 0)
    {
        nums.push(num % 1000);
        num /= 1000;
    }
    while (!nums.empty())
    {
        if (nums.size() == 2 && nums.top() >= 1 && nums.top() <= 4)
        {
            for (int i = 0; i < nums.top(); i++)
            {
                cur += 'M';
            }
        }
        else
            cur += readHundred(nums.top());
        nums.pop();
    }
    return cur;
}
int main()
{
    int num = 1994;
    cout << intToRoman(num) << endl;
    return 0;
}