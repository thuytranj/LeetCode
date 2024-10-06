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
void insertToBST(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    TreeNode *p = root, *lst = NULL;
    while (p)
    {
        lst = p;
        if (val < p->val)
            p = p->left;
        else
            p = p->right;
    }
    if (val < lst->val)
        lst->left = new TreeNode(val);
    else
        lst->right = new TreeNode(val);
}
void help(TreeNode *root, int cnt, int &res)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
    {
        res = min(res, cnt);
        return;
    }
    help(root->left, cnt + 1, res);
    help(root->right, cnt + 1, res);
}
int minDepth(TreeNode *root)
{
    int res = INT_MAX;
    help(root, 1, res);
    return res;
}
int main()
{
    // int n, x;
    // cin >> n;
    // TreeNode *root = NULL;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> x;
    //     insertToBST(root, x);
    // }
    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(15);
    root->right->right->right = new TreeNode(7);
    root->right->right->right->right = new TreeNode(20);
    cout << minDepth(root) << endl; // Prints the minimum depth of the binary tree.
    return 0;
}