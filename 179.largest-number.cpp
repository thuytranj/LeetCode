#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool cmp(const string &a, const string &b)
{
    return a + b > b + a;
}
string largestNumber(vector<int> &nums)
{
    vector<string> arr(nums.size());
    for (int i = 0; i < nums.size(); i++)
        arr[i] = to_string(nums[i]);

    sort(arr.begin(), arr.end(), cmp);
    if (arr[0] == "0")
        return "0";
    string res;
    for (string i : arr)
        res += i;
    return res;
}
int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    return 0;
}