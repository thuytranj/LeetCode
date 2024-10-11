#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int tilt(TreeNode *root, int &sum)
{
    if (!root)
        return 0;
    int leftSum = tilt(root->left, sum);
    int rightSum = tilt(root->right, sum);
    sum += abs(leftSum - rightSum);
    return root->val + leftSum + rightSum;
}
int findTilt(TreeNode *root)
{
    int res = 0;
    tilt(root, res);
    return res;
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << findTilt(root) << endl;
    return 0;
}