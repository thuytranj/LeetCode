#include <iostream>
#include <set>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};
bool findTarget(TreeNode *root, int k)
{
    if (!root)
        return 0;
    set<int> s;
    queue<TreeNode *> q;
    q.push(root);
    s.insert(root->val);

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (cur->left)
        {
            if (s.find(k - cur->left->val) != s.end())
                return 1;
            else
                s.insert(cur->left->val);
            q.push(cur->left);
        }

        if (cur->right)
        {
            if (s.find(k - cur->right->val) != s.end())
                return 1;
            else
                s.insert(cur->right->val);
            q.push(cur->right);
        }
    }

    return 0;
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);

    if (findTarget(root, 28))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}