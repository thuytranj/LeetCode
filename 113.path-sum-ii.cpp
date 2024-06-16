#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};
void solve (vector<vector<int> > &res, TreeNode *root, vector<int> &cur, int tmp, int targetSum) {
    if (root==NULL) return;
    cur.push_back(root->val);
    tmp += root->val;
    if (root->left==NULL && root->right==NULL && tmp==targetSum) {
        res.push_back(cur);
    }
    else {
        solve(cur, root->left, cur, tmp, targetSum);
        solve(cur, root->right, cur, tmp, targetSum);
    }
    cur.pop_back();
    tmp-=root->val;
}
vector<vector<int> > pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int> > res;
    vector<int> cur;
    solve(res, root, cur, 0, targetSum);
    return res;
}
int main () {

    return 0; 
}