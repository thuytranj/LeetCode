#include <iostream>
#include <set>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int helper (TreeNode* root, int &res) {
    if (!root) return 0;
    int left = helper(root->left, res);
    int right = helper(root->right, res);
    int leftPath = (root->left && root->left->val == root->val)? left+1 : 0;
    int rightPath = (root->right && root->right->val == root->val)? right+1 : 0;

    res = max(res, leftPath+rightPath);
    return max(leftPath, rightPath);    
}
int longestUnivaluePath(TreeNode *root)
{
    if (!root) return 0;
    int res = 0;
    helper(root, res);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    cout << longestUnivaluePath(root) << endl;
    return 0;
}