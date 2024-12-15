#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
{
    if (nums.size()<1) return 0;
    set<int> s;
    for (int i=0;i<nums.size();i++) {
        if (i>indexDiff) s.erase (nums[i-indexDiff-1]);
        auto pos=s.lower_bound(nums[i]-valueDiff);
        if (pos!=s.end() && *pos<=nums[i]+valueDiff) return 1;
    
        s.insert(nums[i]); 
    }
    return 0;
}
int main()
{
    vector<int> nums = {1, 5, 9, 1, 5, 9};
    int indexDiff = 2;
    int valueDiff = 3;
    cout << containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) << endl;
    return 0;
}