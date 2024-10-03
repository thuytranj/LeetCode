#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void insertNode(TreeNode *&root, int val)
{
    TreeNode *newNode = new TreeNode(val);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    TreeNode *p = root, *lst = NULL;
    while (p)
    {
        lst = p;
        if (val < p->val)
            p = p->left;
        else
            p = p->right;
    }
    if (val < lst->val)
        lst->left = newNode;
    else
        lst->right = newNode;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size()==0)
        return NULL;
    int mid = nums.size() / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    vector<int> a(nums.begin(), nums.begin() + mid);
    vector<int> b(nums.begin() + mid + 1, nums.end());
    root->left = sortedArrayToBST(a);
    root->right = sortedArrayToBST(b);
    return root;
}
void print(TreeNode *root)
{
    if (root)
    {
        print(root->left);
        cout << root->val << ' ';
        print(root->right);
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    TreeNode *root = sortedArrayToBST(nums);
    print(root);
    cout << endl;
    return 0;
}