#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;
// Runtime 15 ms. Beats 96.85% of users with C++
// Memory 32.13 MB. Beats 37.37% of users with C++
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *createTree(vector<int> nums)
{
    TreeNode *root = new TreeNode(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        TreeNode *p = root;
        bool same = false;
        while ((nums[i] < p->val && p->left) || (nums[i] > p->val && p->right))
        {
            if (nums[i] < p->val)
                p = p->left;
            else
                p = p->right;
        }
        if (nums[i] != p->val)
        {
            if (nums[i] < p->val)
                p->left = new TreeNode(nums[i]);
            else
                p->right = new TreeNode(nums[i]);
        }
    }
    return root;
}
TreeNode *smallestData(TreeNode *root)
{
    if (root->left == NULL)
        return root;
    return smallestData(root->left);
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            TreeNode *tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL)
        {
            TreeNode *tmp = root->left;
            delete root;
            return tmp;
        }
        TreeNode *tmp = smallestData(root->right);
        root->val = tmp->val;
        root->right = deleteNode(root->right, tmp->val);
    }
    return root;
}
void inOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->val << ' ';
    inOrderTraversal(root->right);
}
void randArr(vector<int> &nums)
{
    int n;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = rand() % 1001;
    }
}
void outputArr(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
}
void deleteTree(TreeNode *&root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
int main()
{
    srand(time(NULL));
    vector<int> nums;
    cout << "Enter the numbers of array: ";
    randArr(nums);
    cout << "Random array: ";
    outputArr(nums);
    TreeNode *root = createTree(nums);
    cout << "Ascending array: ";
    inOrderTraversal(root);
    cout << endl;
    int num;
    cout << "Enter the number to delete: ";
    cin >> num;
    cout << "Array after deleted: ";
    inOrderTraversal(deleteNode(root, num));
    deleteTree(root);
    return 0;
}
