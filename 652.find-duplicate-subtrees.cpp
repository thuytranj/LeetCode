#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};
string helper (TreeNode* root, unordered_map <string, int> &m, vector<TreeNode*> &res) {
    if (!root)
        return "#";
    string s = to_string(root->val) + ", " + helper(root->left, m, res) + ", " + helper(root->right, m, res);
    if (++m[s]==2)
        res.push_back(root);
    return s;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    if (!root)
        return vector<TreeNode *>();
    unordered_map<string, int> m;
    vector<TreeNode*> res;
    helper(root, m, res);
    return res;
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
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(4);
    // root->right->left->left = new TreeNode(4);

    vector<TreeNode *> res = findDuplicateSubtrees(root);
    for (auto i : res)
    {
        bfs(i);
        cout << endl;
    }
    return 0;
}