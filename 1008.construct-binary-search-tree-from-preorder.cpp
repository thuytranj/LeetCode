#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void insert(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    TreeNode *p = root, *lst = NULL;
    TreeNode *newNode = new TreeNode(val);
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
int getIndex(vector<int> nums, int start, int val)
{
    for (int i = start; i < nums.size(); i++)
    {
        if (nums[i] > val)
            return i;
    }
    return nums.size();
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    if (preorder.size() == 0)
        return NULL;
    TreeNode *root = new TreeNode(preorder[0]);
    int leftIndex = getIndex(preorder, 1, root->val);
    vector<int> a(preorder.begin() + 1, preorder.begin() + leftIndex);
    vector<int> b(preorder.begin() + leftIndex, preorder.end());
    root->left = bstFromPreorder(a);
    root->right = bstFromPreorder(b);
    return root;
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << ' ';
    print(root->left);
    print(root->right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> preorder(n);
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    root = bstFromPreorder(preorder);
    print(root);
    return 0;
}