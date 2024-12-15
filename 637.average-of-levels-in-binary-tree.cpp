#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};
vector<double> averageOfLevels(TreeNode *root)
{
    if (!root)
        return vector<double>();
    queue<TreeNode *> q;
    vector<double> res;
    q.push(root);
    double sum, cnt;

    while (!q.empty())
    {
        int s = q.size();
        sum = cnt = 0;

        for (int i = 0; i < s; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            sum += cur->val;
            cnt++;

            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }

        res.push_back(sum / cnt);
    }

    return res;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);

    vector<double> res = averageOfLevels(root);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}