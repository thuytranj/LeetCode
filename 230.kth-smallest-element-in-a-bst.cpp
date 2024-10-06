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
void help(TreeNode *root, int &cnt, int k, int &res)
{
    if (root == NULL)
        return;
    help(root->left, cnt, k, res);
    cnt++;
    if (cnt == k)
    {
        res = root->val;
        return;
    }
    help(root->right, cnt, k, res);
}
int kthSmallest(TreeNode *root, int k)
{
    int res = 0, cnt = 0;
    help(root, cnt, k, res);
    return res;
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
    cin >> x;
    cout << kthSmallest(root, x) << endl;
    return 0;
}