#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Runtime 4 ms. Beats 95.88% of users with C++
// Memory 19.4 MB. Beats 23.47% of users with C++
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<TreeNode *> helper(int start, int end)
{
    if (start > end)
        return vector<TreeNode *>();
    if (start == end)
        return vector<TreeNode *>(1, new TreeNode(start));
    vector<TreeNode *> res;
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = helper(start, i - 1);
        vector<TreeNode *> right = helper(i + 1, end);
        if (left.size() == 0)
        {
            for (int j = 0; j < right.size(); j++)
            {
                res.push_back(new TreeNode(i, NULL, right[j]));
            }
        }
        else if (right.size() == 0)
        {
            for (int j = 0; j < left.size(); j++)
            {
                res.push_back(new TreeNode(i, left[j], NULL));
            }
        }
        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                res.push_back(new TreeNode(i, left[j], right[k]));
            }
        }
    }
    return res;
}
vector<TreeNode *> generateTrees(int n)
{
    return helper(1, n);
}
void prinfBFS (TreeNode* root){
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *tmp = q.front();
        q.pop();
        cout << tmp->val << ' ';
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<TreeNode *> res = generateTrees(n);
    for (int i=0;i<res.size();i++) {
        prinfBFS(res[i]);
        cout << endl;
    }
    return 0;
}