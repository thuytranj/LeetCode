#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    if (!root)
        return NULL;
    if (root->val < low)
    {
        return trimBST (root->right, low, high);
    }

    if (root->val > high)
    {
        return trimBST (root->left, low, high);
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}
void bfs(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        cout << q.front()->val << ' ';

        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    TreeNode *res = trimBST(root, 1, 2);
    bfs(root);
    return 0;
}