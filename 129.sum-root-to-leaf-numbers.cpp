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
void help(TreeNode *root, int num, int &res)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        res += 10*num + root->val;
    help(root->left, num * 10 + root->val, res);
    help(root->right, num * 10 + root->val, res);
}
int sumNumbers(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int res = 0;
    help(root, 0, res);
    return res;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    int maxVal = max(q->val, p->val);
    int minVal = min(q->val, p->val);
    TreeNode *tmp = root;
    while (tmp)
    {
        if (minVal < tmp->val && maxVal < tmp->val)
            tmp = tmp->left;
        else if (minVal > tmp->val && maxVal > tmp->val)
            tmp = tmp->right;
        else
            break;
    }
    return tmp;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    return 0;
}