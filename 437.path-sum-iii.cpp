#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void help(TreeNode *root, int &cnt, long long sum, int target)
{
    if (!root)
        return;

    sum += root->val;
    if (sum == (long long) target)
        cnt++;
    help(root->left, cnt, sum, target);
    help(root->right, cnt, sum, target);
}
void help2(TreeNode *root, int &cnt, int target)
{
    if (!root)
        return;
    help(root, cnt, 0, target);
    help2(root->left, cnt, target);
    help2(root->right, cnt, target);
}
int pathSum(TreeNode *root, int targetSum)
{
    int cnt = 0;
    help2(root, cnt, targetSum);
    return cnt;
}
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    cout << pathSum(root, 18) << endl;
    return 0;
}