#include <iostream>
#include <sstream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Encodes a tree to a single string.
void helpSerialize(TreeNode *root, string &res)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            res += to_string(cur->val) + ",";
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
    res.erase(res.begin() + res.size() - 1);
}
string serialize(TreeNode *root)
{
    string res;
    helpSerialize(root, res);
    return res;
}
TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}
// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    TreeNode *root = NULL;
    stringstream ss(data);
    string node;
    while (getline(ss, node, ','))
    {
        root = insert(root, stoi(node));
    }
    return root;
}
void dfs(TreeNode *root)
{
    if (!root)
        return;
    dfs(root->left);
    cout << root->val << ' ';
    dfs(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(13);

    string data = serialize(root);
    dfs(root);
    cout << endl;

    cout << data << endl;

    TreeNode *root2 = deserialize(data);
    dfs(root2);
    cout << endl;

    return 0;
}