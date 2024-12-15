#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size() / 3;
    vector<int> res;
    unordered_map<int, int> m;
    for (int i : nums)
    {
        m[i]++;
        if (m[i] == n + 1)
            res.push_back(i);
    }
    return res;
}
int main()
{
    vector<int> nums = {1, 2};
    vector<int> res = majorityElement(nums);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}