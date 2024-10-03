#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void insertNode(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    TreeNode *newNode = new TreeNode(val), *p = root, *lst = NULL;
    while (p)
    {
        lst = p;
        if (val < p->val)
            p = p->left;
        else
            p = p->right;
    }
    if (val < lst->val)
        lst->left = newNode;
    else
        lst->right = newNode;
}
void helper(TreeNode *root, int tmp, int &res)
{
    if (root == NULL)
        return;
    tmp++;
    res = max(res, tmp);
    helper(root->left, tmp, res);
    helper(root->right, tmp, res);
}
int maxDepth(TreeNode *root)
{
    int res = 0, tmp = 0;
    helper(root, tmp, res);
    return res;
}
int main()
{
    srand(time(0));
    int n, x;
    cin >> n;
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertNode(root, x);
    }
    cout << maxDepth(root) << endl;
    return 0;
}