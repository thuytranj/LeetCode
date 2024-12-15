#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void serializeHelper(TreeNode *root, stringstream &s)
{
    if (!root)
    {
        s << "null,";
        return;
    }

    s << root->val << ",";
    serializeHelper(root->left, s);
    serializeHelper(root->right, s);
}
// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    stringstream ss;
    serializeHelper(root, ss);
    return ss.str();
}

TreeNode *deserializeHelper(stringstream &ss)
{
    string val;
    getline(ss, val, ',');

    if (val == "null")
    {
        return NULL;
    }

    TreeNode *node = new TreeNode(stoi(val));
    node->left = deserializeHelper(ss);
    node->right = deserializeHelper(ss);
    return node;
}
// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    stringstream ss(data);
    return deserializeHelper(ss);
}

void bfs(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *tmp = q.front();
        q.pop();
        if (tmp)
            cout << tmp->val << " ";
        else
            cout << "NULL ";
        if (tmp)
        {
            q.push(tmp->left);
            q.push(tmp->right);
        }
    }
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);

    string encoded = serialize(root);
    cout << "Encoded: " << encoded << endl;

    TreeNode *root2 = deserialize(encoded);
    bfs(root2);
    return 0;
}