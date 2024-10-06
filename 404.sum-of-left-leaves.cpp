#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void help(TreeNode *root, int &sum)
{
    if (!root || (!root->left && !root->right))
        return;
    help(root->left, sum);
    help(root->right, sum);
    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val;
}
int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    help(root, sum);
    return sum;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << sumOfLeftLeaves(root) << endl;
    return 0;
}