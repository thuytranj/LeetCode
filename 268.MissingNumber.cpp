#include <iostream>
#include <vector>
using namespace std;

// Runtime 22 ms. Beats 10.33% of users with C++
// Memory 20.95 MB. Beats 19.74% of users with C++

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
            return i;
    }
    return nums.size();
}
int main()
{
    vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber (nums)<<endl;
     return 0;
}