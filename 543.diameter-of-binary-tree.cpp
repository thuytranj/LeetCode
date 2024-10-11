#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int help(TreeNode *root, int &res)
{
    if (!root)
        return 0;
    int l = help(root->left, res);
    int r = help(root->right, res);
    res = max(res, l + r);
    return max(l, r) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    int res = INT_MIN;
    help(root, res);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}