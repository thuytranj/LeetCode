#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Runtime 20 ms. Beats 15.28% of users with C++
// Memory 20.8 MB. Beats 5.34% of users with C++
int majorityElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    map<int, int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = res.find(nums[i]);
        if (it == res.end())
        {
            res.insert(pair<int, int>(nums[i], 1));
        }
        else
        {
            if (res[nums[i]] + 1 > nums.size() / 2)
                return nums[i];
            res[nums[i]]++;
        }
    }
    return 0;
}
int main()
{
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement (nums)<<endl;
     return 0;
}