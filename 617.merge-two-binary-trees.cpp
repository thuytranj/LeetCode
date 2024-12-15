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
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return NULL;
    else if (root2 == NULL)
        return root1;
    else if (root1 == NULL)
        return root2;
    else
    {
        TreeNode *root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
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
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    // root2->right = new TreeNode(3);
    // root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(3);

    TreeNode *root3 = mergeTrees(root1, root2);
    bfs(root3);
    return 0;
}