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
void help(TreeNode *root, vector<TreeNode *> &ancestor1, TreeNode *p, vector<TreeNode *> &ancestor2, TreeNode *q, bool &foundP, bool &foundQ)
{
    if (!root)
        return;
    if (!foundP)
        ancestor1.push_back(root);
    if (!foundQ)
        ancestor2.push_back(root);
    if (root->val == p->val)
        foundP = true;
    if (root->val == q->val)
        foundQ = true;

    help(root->left, ancestor1, p, ancestor2, q, foundP, foundQ);
    help(root->right, ancestor1, p, ancestor2, q, foundP, foundQ);

    if (!foundP)
        ancestor1.pop_back();
    if (!foundQ)
        ancestor2.pop_back();
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> ancestor1, ancestor2;
    bool foundP = 0, foundQ = 0;

    help(root, ancestor1, p, ancestor2, q, foundP, foundQ);

    int s = min(ancestor1.size(), ancestor2.size()), i = 0;
    while (i < s && ancestor1[i] == ancestor2[i])
    {
        i++;
        if (ancestor1[i - 1]->val == p->val || ancestor1[i - 1]->val == q->val)
            break;
    }
    return ancestor1[i - 1];
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *p = lowestCommonAncestor(root, root->left->left, root->right->left);
    cout << p->val << endl;
    return 0;
}