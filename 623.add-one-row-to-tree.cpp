#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};
TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (!root)
    {
        if (depth == 1)
            return new TreeNode(val);
        else
            return NULL;
    }
    if (depth == 1)
    {
        TreeNode *tmp = new TreeNode(val, root, NULL);
        return tmp;
    }
    queue<TreeNode *> q;
    q.push(root);
    int cnt = 1;

    while (!q.empty() && cnt < depth - 1)
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            TreeNode *cur = q.front();
            q.pop();

            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        cnt++;
    }

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        TreeNode *left = cur->left;
        cur->left = new TreeNode(val);
        cur->left->left = left;

        TreeNode *right = cur->right;
        cur->right = new TreeNode(val);
        cur->right->right = right;
    }
    return root;
}
void bfs(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *tmp = q.front();
        q.pop();
        cout << tmp->val << " ";
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    TreeNode *res = addOneRow(root, 1, 3);
    bfs(res);
    return 0;
}