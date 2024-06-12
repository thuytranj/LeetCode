#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Runtime 12 ms. Beats 21.48% of users with C++
// Memory 20.3 MB. Beats 27.41% of users with C++
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void helper(TreeNode *root, TreeNode *&maxLeft, TreeNode *minRight)
{
    if (root == NULL)
        return;
    if (root->left == NULL)
        maxLeft = root;
    if (root->right == NULL)
        minRight = root;
    helper(root->left, maxLeft, minRight);
    if (maxLeft->val > root->val)
    {
        swap(maxLeft->val, root->val);
        return;
    }
    if (maxRight->val < root->val)
    {
        swap(maxRight->val, root->val);
        return;
    }
    helper(root->right, maxLeft, minRight);
}
void recoverTree(TreeNode *root)
{
    if (root == NULL)
        return;
    TreeNode *maxLeft, minRight;
    helper(root, maxLeft, minRight);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    recoverTree(root);
    return 0;
}