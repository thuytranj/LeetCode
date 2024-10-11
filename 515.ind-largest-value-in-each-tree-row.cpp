#include <iostream>
#include <queue>
#include <set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> largestValues(TreeNode *root)
{
    if (!root)
        return vector<int>();
    queue<TreeNode *> q;
    vector<int> res;
    set<int> v;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            v.insert(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        res.push_back(*v.rbegin());
        v.clear();
    }
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(-1);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(5);
    // root->left->right = new TreeNode(3);
    // root->right->right = new TreeNode(9);

    vector<int> res = largestValues(root);

    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}