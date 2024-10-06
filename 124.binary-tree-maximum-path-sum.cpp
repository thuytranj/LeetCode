#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int pathSum(TreeNode *root, int &sum)
{
    if (root == NULL)
        return 0;
    if (!root->left && !root->right)
    {
        sum = max(sum, root->val);
        return root->val;
    }
    int left = max(0, pathSum(root->left, sum));
    int right = max(0, pathSum(root->right, sum));

    int currSum = root->val + left + right;
    sum = max(sum, currSum);

    return root->val + max(left, right);
}

int maxPathSum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int sum = INT_MIN;
    int tmp = pathSum(root, sum);
    return sum;
}
int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    cout << maxPathSum(root) << endl;
    return 0;
}