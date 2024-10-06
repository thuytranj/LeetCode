#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void help(TreeNode *root, int tmp, int target, bool &valid)
{
    if (root == NULL || valid)
        return;
    if (!root->left && !root->right)
    {
        if (tmp + root->val == target)
            valid = 1;
    }
    help(root->left, tmp + root->val, target, valid);
    help(root->right, tmp + root->val, target, valid);
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    bool valid = 0;
    help(root, 0, targetSum, valid);
    return valid;
}
int main()
{
    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(8);
    // root->left->left = new TreeNode(11);
    // root->right->left = new TreeNode(13);
    // root->right->right = new TreeNode(4);
    // root->left->left->left = new TreeNode(7);
    // root->left->left->right = new TreeNode(2);
    // root->right->right->right = new TreeNode(1);
    int targetSum = 5;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    if (hasPathSum(root, targetSum))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}