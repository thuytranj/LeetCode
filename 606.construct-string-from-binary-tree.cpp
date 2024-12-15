#include <iostream>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};
string tree2str(TreeNode *root)
{
    if (root == NULL)
        return "";
    string result = to_string(root->val);
    if (root->left == NULL && root->right == NULL)
        return result;
    result += "(" + tree2str(root->left) + ")";
    if (root->right != NULL)
        result += "(" + tree2str(root->right) + ")";
    return result;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    cout << tree2str(root) << endl;
    return 0;
}