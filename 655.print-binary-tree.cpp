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
int getHeight(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}
vector<vector<string>> printTree(TreeNode *root)
{
    int height = getHeight(root) - 1;
    int n = (1 << (height + 1)) - 1;
    vector<vector<string>> res(height + 1, vector<string>(n, "*"));

    queue<pair<TreeNode *, int>> q;
    q.push({root, (n - 1) / 2});
    res[0][(n - 1) / 2] = to_string(root->val);
    int r = 0;

    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            auto tmp = q.front();
            q.pop();

            if (tmp.first->left)
            {
                q.push({tmp.first->left, tmp.second - (1 << (height - r - 1))});
                res[r + 1][tmp.second - (1 << (height - r - 1))] = to_string(tmp.first->left->val);
            }

            if (tmp.first->right)
            {
                q.push({tmp.first->right, tmp.second + (1 << (height - r - 1))});
                res[r + 1][tmp.second + (1 << (height - r - 1))] = to_string(tmp.first->right->val);
            }
        }
        r++;
    }

    return res;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    vector<vector<string>> res = printTree(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}