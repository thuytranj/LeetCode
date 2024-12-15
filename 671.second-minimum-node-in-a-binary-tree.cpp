#include <iostream>
#include <set>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int findSecondMinimumValue(TreeNode *root)
{
    if (!root)
        return -1;
    set<int> s;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        s.insert(q.front()->val);

        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }

    set<int>::iterator it = s.begin();
    if (++it == s.end())
        return -1;
    return *it;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    cout << findSecondMinimumValue(root) << endl;
    return 0;
}