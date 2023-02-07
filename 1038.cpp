/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void rebuild(TreeNode *root, int &pre) {
        if (root == nullptr)  return ;
        rebuild(root->right, pre);
        root->val += pre;
        pre = root->val;
        rebuild(root->left, pre);
        return ;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int pre = 0;
        rebuild(root, pre);
        return root;
    }
};
