#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int pathSum(TreeNode *root, int &sum)
{
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
        return root->val;
    int left = pathSum(root->left, sum);
    int right = pathSum(root->right, sum);

    if (root->left && root->right)
    {
        sum = max(sum, root->val + left + right);
        return root->val + max(left, right);
    }
    else if (root->left)
        return root->val + left;
    else
        return root->val + right;
}
int maxPathSum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int sum = INT_MIN;
    int ans = pathSum(root, sum);
    if (root->left && root->right)
        return sum;
    return max(sum, ans);
}

int main()
{
    TreeNode *root = new TreeNode(-15);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(-8);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(-3);
    root->right->right->right = new TreeNode(0);
    root->right->right->right->left = new TreeNode(4);
    root->right->right->right->right = new TreeNode(-1);
    root->right->right->right->right->left = new TreeNode(10);

    // TreeNode *root = new TreeNode(3);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(5);
    // root->left->left = new TreeNode(-10);
    // root->left->right = new TreeNode(4);
    cout << maxPathSum(root) << endl;
    return 0;
}