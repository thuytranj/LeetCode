#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSameTree(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->val != root2->val)
        return false;
    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root && !subRoot)
        return 1;
    if (!root || !subRoot)
        return 0;
    if (root->val == subRoot->val)
    {
        if (isSameTree(root, subRoot))
            return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    if (isSubtree(root, subRoot))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}