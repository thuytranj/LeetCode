#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void left(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    if (root->left || root->right)
        res.push_back(root->val);
    if (root->left)
        left(root->left, res);
    else
        left(root->right, res);
}
void right(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    if (root->right) right(root->right, res);
    else right (root->left, res);
    if (root->left || root->right)
        res.push_back(root->val);
}
void leaf(TreeNode *root, vector<int> &res)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        res.push_back(root->val);
    leaf(root->left, res);
    leaf(root->right, res);
}
vector<int> boundary(TreeNode *root)
{
    if (root == NULL)
        return vector<int>();
    vector<int> res;
    res.push_back(root->val);
    left(root->left, res);
    leaf(root, res);
    int tmp = res.size();
    right(root->right, res);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->right = new TreeNode(8);
    root->left->left->right->left = new TreeNode(9);
    root->left->left->right->left->left = new TreeNode(10);
    root->left->left->right->left->right = new TreeNode(11);
    vector<int> res = boundary(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}