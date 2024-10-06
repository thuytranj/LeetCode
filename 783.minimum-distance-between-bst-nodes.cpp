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
void insert(TreeNode *&root, int val)
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
void help(TreeNode *root, int &tmp, int &min)
{
    if (root == NULL)
        return;
    help(root->left, tmp, min);
    if (tmp!=INT_MIN && abs(root->val - tmp) < min)
        min = abs(root->val - tmp);
    tmp = root->val;
    help(root->right, tmp, min);
}
int minDiffInBST(TreeNode *root)
{
    int tmp = INT_MIN, min=INT_MAX;
    help(root, tmp, min);
    return min;
}
int main()
{
    int n, x;
    cin >> n;
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(root, x);
    }
    cout << minDiffInBST(root) << endl;
    return 0;
}