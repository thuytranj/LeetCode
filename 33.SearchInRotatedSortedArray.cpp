#include <iostream>
#include <vector>
using namespace std;

// Runtime 3 ms. Beats 62.93% of users with C++
// Memory 11.27 MB. Beats 99.54% of users with C++

int search(vector<int> &nums, int target)
{
    vector<int>::iterator i = find(nums.begin(), nums.end(), target);
    if (i != nums.end())
        return i - nums.begin();
    else
        return -1;
}
int main()
{
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target=0;
    cout<<search (nums, target)<<endl;
    return 0;
}