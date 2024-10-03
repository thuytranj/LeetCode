#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *getParentAndFindNode(TreeNode *root, int target, map<TreeNode *, TreeNode *> &parent)
{
    if (root == NULL)
        return NULL;
    queue<TreeNode *> q;
    TreeNode *res;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->val == target)
                res = cur;
            if (cur->left)
            {
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right)
            {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
    return res;
}
int minTime(TreeNode *root, int target)
{
    map<TreeNode *, TreeNode *> parent; 
    TreeNode *node = getParentAndFindNode(root, target, parent); // find the node with value = target and get parent of each node
    int time = 0;
    map<TreeNode *, int> vis;   //check if node was burned

    // use bfs traversal each node
    // burn child and parent of node
    // pop node of the queue 
    // push left, right child of node
    queue<TreeNode *> q;        
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        int sz = q.size();
        bool fl = 0;
        for (int i = 0; i < sz; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left && !vis[cur->left])
            {
                fl = 1;
                q.push(cur->left);
                vis[cur->left] = 1;
            }
            if (cur->right && !vis[cur->right])
            {
                fl = 1;
                q.push(cur->right);
                vis[cur->right] = 1;
            }
            if (parent[cur] && !vis[parent[cur]])
            {
                fl = 1;
                q.push(parent[cur]);
                vis[parent[cur]] = 1;
            }
        }
        if (fl)
            time++;
    }
    return time;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->right = new TreeNode(10);
    cout << minTime(root, 8) << endl;
    return 0;
}