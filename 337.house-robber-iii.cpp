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
pair<int, int> help (TreeNode* root) {
    if (!root)
        return {0, 0};

    pair<int, int> maxL = help(root->left);
    pair<int, int> maxR = help(root->right);

    int robCur = root->val+maxL.second+maxR.second;
    int notRobCuur = max(maxL.first, maxL.second) + max(maxR.first, maxR.second);

    return {robCur, notRobCuur};
}
int rob(TreeNode *root)
{
    pair<int, int> res = help(root);
    return max(res.first, res.second);
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << rob(root) << endl;
    return 0;
}