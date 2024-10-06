#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    int maxVal = max(q->val, p->val);
    int minVal = min(q->val, p->val);
    TreeNode *tmp = root;
    while (tmp)
    {
        if (minVal < tmp->val && maxVal < tmp->val)
            tmp = tmp->left;
        else if (minVal > tmp->val && maxVal > tmp->val)
            tmp = tmp->right;
        else
            break;
    }
    return tmp;
}
int main (){
    return 0;
}