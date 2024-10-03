#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *build(vector<int> postorder, int inorderLeft, int inorderRight, int postorderLeft, int postorderRight, unordered_map<int, int> inorderIndex)
{
    if (postorderLeft > postorderRight)
        return NULL;
    TreeNode *root = new TreeNode(postorder[postorderRight]);
    int x = inorderIndex[postorder[postorderRight]];
    root->left = build(postorder, inorderLeft, x - 1, postorderLeft, postorderLeft + x - inorderLeft - 1, inorderIndex);
    root->right = build(postorder, x + 1, inorderRight, postorderLeft + x - inorderLeft, postorderRight - 1, inorderIndex);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inorderIndex;
    for (int i = 0; i < inorder.size(); i++)
        inorderIndex[inorder[i]] = i;
    return build(postorder, 0, postorder.size() - 1, 0, postorder.size() - 1, inorderIndex);
}
void print(TreeNode *root)
{
    if (root)
    {
        print(root->left);
        cout << root->val << " ";
        print(root->right);
    }
}
int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = buildTree(inorder, postorder);
    print(root);
    cout << endl;
    return 0;
}