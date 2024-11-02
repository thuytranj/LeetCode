#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

vector<int> smallestRange(vector<vector<int>> &nums)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    for (int i = 0; i < nums.size(); i++)
    {
        q.push({nums[i][0], {i, 0}});
    }

    vector<pair<int, int>> index;

    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();
        index.push_back(tmp.second);

        if (tmp.second.second + 1 < nums[tmp.second.first].size())
        {
            q.push({nums[tmp.second.first][tmp.second.second + 1], {tmp.second.first, tmp.second.second + 1}});
        }
    }

    int start = INT_MAX, end = INT_MIN;

    unordered_map<int, int> freq; 
    int min_range = INT_MAX;
    int i = 0, j = 0;

    while (j < index.size())
    {
        while (j < index.size() && freq.size() < nums.size())
        {
            freq[index[j].first]++;
            j++;
        }

        while (i < j && freq.size() == nums.size())
        {
            int current_start = nums[index[i].first][index[i].second];
            int current_end = nums[index[j - 1].first][index[j - 1].second];

            if (current_end - current_start < min_range)
            {
                start = current_start;
                end = current_end;
                min_range = current_end - current_start;
            }

            freq[index[i].first]--;
            if (freq[index[i].first] == 0)
            {
                freq.erase(index[i].first);
            }
            i++;
        }
    }

    return {start, end};
}

int main()
{
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> res = smallestRange(nums);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}