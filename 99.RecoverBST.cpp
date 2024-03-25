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
void minValue(TreeNode *root, TreeNode *&min)
{
    if (root == NULL)
    {
        return;
    }
    minValue(root->left, min);
    if (!min || root->val < min->val)
        min = root;
    minValue(root->right, min);
}
void maxValue(TreeNode *root, TreeNode *&max)
{
    if (root == NULL)
    {
        return;
    }
    maxValue(root->left, max);
    if (!max || root->val > max->val)
        max = root;
    maxValue(root->right, max);
}
void recoverTree(TreeNode *root)
{
    TreeNode *maxLeft = root->left, *minRight = root->right;
    maxValue(root->left, maxLeft);
    minValue(root->right, minRight);
    if (maxLeft && maxLeft->val > root->val)
    {
        swap(maxLeft->val, root->val);
        return;
    }
    if (minRight && minRight->val < root->val)
    {
        swap(minRight->val, root->val);
        return;
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    recoverTree(root);
    return 0;
}