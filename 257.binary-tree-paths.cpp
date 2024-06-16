#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void solve(TreeNode *root, vector<string> &res, string tmp)
{
    if (root == NULL)
        return;

    tmp += to_string(root->val);

    if (root->left == NULL && root->right == NULL)
    {
        res.push_back(tmp);
        return;
    }

    tmp += "->";
    solve(root->left, res, tmp);
    solve(root->right, res, tmp);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> res;
    if (root == NULL)
        return res;
    solve(root, res, "");
    return res;
}
int main () {
    return 0;
}