#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int sumTree(TreeNode *root, unordered_map<int, int> &map)
{
    if (!root)
        return 0;

    int leftSum = sumTree(root->left, map);
    int rightSum = sumTree(root->right, map);
    int res = leftSum + rightSum + root->val;

    map[res]++;

    return res;
}
vector<int> findFrequentTreeSum(TreeNode *root)
{
    unordered_map<int, int> map;
    sumTree(root, map);

    vector<int> res;
    int maxCount = 0;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        if (it->second > maxCount)
        {
            maxCount = it->second;
            res.clear();
            res.push_back(it->first);
        }
        else if (it->second == maxCount)
        {
            res.push_back(it->first);
        }
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-5);
    vector<int> res = findFrequentTreeSum(root);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}