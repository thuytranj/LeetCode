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
void help(TreeNode *root, unordered_map<int, int> &m)
{
    if (!root)
        return;
    m[root->val]++;
    help(root->left, m);
    help(root->right, m);
}
vector<int> findMode(TreeNode *root)
{
    unordered_map<int, int> m;
    help(root, m);
    vector<int> res;
    int max = 1;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second == max)
            res.push_back(it->second);
        else if (it->second > max)
        {
            res.clear();
            res.push_back(it->first);
            max = it->second;
        }
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(2);
    vector<int> res = findMode(root);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}