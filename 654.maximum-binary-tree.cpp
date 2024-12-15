#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};
TreeNode *helper(vector<int> &nums, int l, int r)
{
    if (l > r)
        return NULL;
    auto posMax = max_element(nums.begin() + l, nums.begin() + r + 1) - nums.begin();
    TreeNode *root = new TreeNode(nums[posMax]);
    root->left = helper(nums, l, posMax - 1);
    root->right = helper(nums, posMax + 1, r);
    return root;
}
TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    return helper(nums, 0, nums.size() - 1);
}
void bfs(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *tmp = q.front();
        q.pop();
        cout << tmp->val << " ";
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
}
int main()
{
    vector<int> nums = {3, 2, 1};
    TreeNode *root = constructMaximumBinaryTree(nums);
    bfs(root);
    return 0;
}