#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int findBottomLeftValue(TreeNode *root)
{
    if (!root)
        return -1;
    queue<TreeNode *> q;
    q.push(root);
    int res = root->val;
    while (!q.empty())
    {
        int s = q.size();
        res = q.front()->val;
        for (int i = 0; i < s; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    cout << findBottomLeftValue(root) << endl;
    return 0;
}