#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};
void help(TreeNode *root, string &res, string cur)
{
    if (root == NULL)
        return;
    cur += ('a' + root->val);

    if (root->left == NULL && root->right == NULL)
    {
        reverse(cur.begin(), cur.end());
        if (res == "" || cur < res)
            res = cur;
        return;
    }
    help(root->left, res, cur);
    help(root->right, res, cur);
}
string smallestFromLeaf(TreeNode *root)
{
    string res = "", cur = "";
    help(root, res, cur);
    return res;
}
int main () {
    return 0;
}