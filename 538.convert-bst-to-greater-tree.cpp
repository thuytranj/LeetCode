#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void help(TreeNode *root, int &sum, vector<int> &sums)
{
    if (!root)
        return;
    help(root->right, sum, sums);
    sum += root->val;
    sums.push_back(sum);
    help(root->left, sum, sums);
}
void convert(TreeNode *&root, int &pos, vector<int> &sums)
{
    if (!root)
        return;

    convert(root->left, pos, sums);
    root->val = sums[sums.size()-1-pos];
    pos++;
    convert(root->right, pos, sums);
}
TreeNode *convertBST(TreeNode *root)
{
    int sum = 0, pos=0;
    vector<int> sums;
    help(root, sum, sums);

    convert(root, pos, sums);

    return root;
}
void print(TreeNode *root)
{
    if (!root)
        return;
    print(root->left);
    cout << root->val << ' ';
    print(root->right);
}
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(8);

    TreeNode *newRoot = convertBST(root);

    print(newRoot);
    return 0;
}