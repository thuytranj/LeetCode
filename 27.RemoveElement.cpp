#include <iostream>
#include <vector>
using namespace std;

// Runtime 0 ms. Beats 100% of users with C++
// Memory 10.46 MB. Beats 26.77% of users with C++

int removeElement(vector<int> &nums, int val)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == val)
        {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}
int main()
{
    vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
    int val=2;
    cout << removeElement (nums, val)<<endl;
    return 0;
}