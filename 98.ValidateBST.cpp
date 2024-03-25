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
int minValue(TreeNode *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(min(minValue(root->left), minValue(root->right)), root->val);
}
int maxValue(TreeNode *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(max(maxValue(root->left), maxValue(root->right)), root->val);
}
bool isValidBST(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (!isValidBST(root->left) || !isValidBST(root->right))
        return false;
    int maxLeft = maxValue(root->left), minRight = minValue(root->right);
    if ((root->left && maxLeft >= root->val) || (root->right && root->val >= minRight))
        return false;
    return true;
}
int main()
{
    return 0;
}