#include <iostream>
#include <vector>
using namespace std;
// Runtime 15 ms. Beats 74.86% of users with C++
// Memory 19.54 MB. Beats 76.97% of users with C++
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *createTree(vector<int> nums)
{
    TreeNode *root = new TreeNode(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        TreeNode *p = root;
        bool same = false;
        while ((nums[i] < p->val && p->left) || (nums[i] > p->val && p->right))
        {
            if (nums[i] < p->val)
                p = p->left;
            else
                p = p->right;
        }
        if (nums[i] != p->val)
        {
            if (nums[i] < p->val)
                p->left = new TreeNode(nums[i]);
            else
                p->right = new TreeNode(nums[i]);
        }
    }
    return root;
}
void inOrder(TreeNode *root, vector<int> &nums)
{
    if (root == NULL)
        return;
    inOrder(root->left, nums);
    nums.push_back(root->val);
    inOrder(root->right, nums);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> nums;
    inOrder(root, nums);
    return nums;
}
int main()
{
    vector<int> nums{1, 2, 9, 10, 4, 1};
    TreeNode *root = createTree(nums);
    vector<int> ans = inorderTraversal(root);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout<<endl;
    return 0;
}