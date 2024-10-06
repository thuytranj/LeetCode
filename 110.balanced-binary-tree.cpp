#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
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
    TreeNode *p = root, *lst = NULL;
    TreeNode *newNode = new TreeNode(val);
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
int height (TreeNode *root, bool &valid)
{
    if (!root)
        return 0;
    int l = height(root->left, valid);
    if (valid) {
        int r=height (root->right, valid);
        if (abs (l-r)>1)
            valid = 0;
        return 1 + max(l, r);
    }
    return -1;
}
bool isBalanced(TreeNode *root)
{
    bool valid = true;
    int h = height(root, valid);
    return valid;
}
int main()
{
    TreeNode *root = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertNode(root, x);
    }
    if (isBalanced(root))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}