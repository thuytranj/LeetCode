#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int widthOfBinaryTree(TreeNode *root)
{
    if (!root) return 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int maxWidth=1;

    while (!q.empty()) {
        auto start = q.front(), end = q.back();
        maxWidth = max(maxWidth, end.second - start.second + 1);

        int s = q.size();
        for (int i=0;i<s;i++) {
            auto node = q.front().first;
            int pos = q.front().second - start.second;
            q.pop();

            if (node->left) q.push({node->left, 2*pos});
            if (node->right) q.push({node->right, 2*pos+1});
        }
    }

    return maxWidth;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    cout << widthOfBinaryTree(root) << endl; // Output: 4
    return 0;
}