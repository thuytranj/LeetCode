#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int> &nums)
{
    if (nums.size()==1)
        return nums[0];
    sort(nums.begin(), nums.end());
    if (nums[0]!=nums[1])
        return nums[0];
    for (int i = 1; i < nums.size()-1; i++)
    {
        if (nums[i]!=nums[i-1] && nums[i]!=nums[i+1])
            return nums[i];
    }
    return nums[nums.size() - 1];
}
int main () {
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
    {
        cin>>nums[i];
    }
    cout<<singleNumber (nums)<<endl;
    return 0;
}