#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Runtime 1428 ms. Beats 7% of users with C++
// Memory 91.5 MB. Beats 87.98% of users with C++

int count(vector<int> &nums, vector<int> &cur, int pos)
{
    if (nums[pos] == cur[0])
    {
        cur.erase(cur.begin());
        return 0;
    }
    int l = 0, r = cur.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (cur[m] == nums[pos])
        {
            while (m != 0 && cur[m - 1] == cur[m])
            {
                m--;
            }
            cur.erase(cur.begin() + m);
            return m;
        }
        else
        {
            if (cur[m] < nums[pos])
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return 0;
}
vector<int> countSmaller(vector<int> &nums)
{
    vector<int> res, cur = nums;
    if (nums.size() == 1)
    {
        res.push_back(0);
        return res;
    }
    sort(cur.begin(), cur.end());
    for (int i = 0; i < nums.size(); i++)
    {
        res.push_back(count(nums, cur, i));
    }
    return res;
}
void output (vector<int> res){
    for (int i=0;i<res.size();i++){
        cout << res[i] << ' ';
    }
    cout<<endl;
}
int main()
{
    vector<int> nums{5, 2, 6, 1};
    vector<int> res = countSmaller(nums);
    output(res);
    return 0;
}