#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *arrayToTree(vector<int> &preorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right, unordered_map<int, int> &inorder_index_map)
{
    // Base case: if the current subtree has no elements
    if (preorder_left > preorder_right)
    {
        return nullptr;
    }

    // The first element in the preorder traversal is the root
    int root_val = preorder[preorder_left];
    TreeNode *root = new TreeNode(root_val);

    // Get the index of the root from the inorder traversal using the hashmap
    int inorder_root_index = inorder_index_map[root_val];

    // Number of nodes in the left subtree
    int left_subtree_size = inorder_root_index - inorder_left;

    // Recursively construct the left and right subtrees
    root->left = arrayToTree(preorder, preorder_left + 1, preorder_left + left_subtree_size, inorder_left, inorder_root_index - 1, inorder_index_map);
    root->right = arrayToTree(preorder, preorder_left + left_subtree_size + 1, preorder_right, inorder_root_index + 1, inorder_right, inorder_index_map);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inorderIndex;
    for (int i = 0; i < inorder.size(); i++)
    {
        inorderIndex[inorder[i]] = i;
    }
    return arrayToTree(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorderIndex);
}
void print(TreeNode *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
    print(root);
    return 0;
}