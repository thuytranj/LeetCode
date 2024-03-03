#include <iostream>
#include <vector>
using namespace std;

// Runtime 91 ms. Beats 12.38% of users with C++
// Memory 14.22 MB. Beats 73.96% of users with C++

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> temp;

    vector<int>::iterator i = find(nums.begin(), nums.end(), target);

    if (i == nums.end())
    {
        temp.emplace_back(-1);
        temp.emplace_back(-1);
        return temp;
    }
    else
    {
        vector<int> cur;
        cur.emplace_back(i - nums.begin());
        while (i != nums.end())
        {
            *i = target + 1;
            temp.emplace_back(i - nums.begin());
            i = find(nums.begin(), nums.end(), target);
        }
        if (temp.size() == 1)
            temp.emplace_back(temp[0]);
        cur.emplace_back(temp[temp.size() - 1]);
        return cur;
    }
}
void output (vector<int> res){
    for (int i=0;i<res.size();i++){
        cout << res[i] << ' ';
    }
    cout<<endl;
}
int main()
{
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 6;
    vector<int> res = searchRange(nums, target);
    output(res);
    return 0;
}