#include <iostream>
#include <queue>
#include <set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void help(TreeNode *root, int &prev, int &res)
{
    if (!root)
        return;
    help(root->left, prev, res);
    res = min(abs(root->val - prev), res);
    prev = root->val;
    help(root->right, prev, res);
}
int getMinimumDifference(TreeNode *root)
{
    int prev = INT_MAX, res = INT_MAX;
    help(root, prev, res);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    cout << getMinimumDifference(root) << endl;
    return 0;
}