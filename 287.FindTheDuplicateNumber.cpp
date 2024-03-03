#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Runtime 197 ms. Beats 8.42% of users with C++
// Memory 88.09 MB. Beats 10.93% of users with C++

int findDuplicate(vector<int> &nums)
{
    set<int> cur;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cur.find(nums[i]) != cur.end())
            return nums[i];
        else
            cur.insert(nums[i]);
    }
    return 0;
}
int main()
{
    vector<int> nums { 1, 3, 4, 2, 2 };
    cout << findDuplicate (nums)<<endl;
    return 0;
}