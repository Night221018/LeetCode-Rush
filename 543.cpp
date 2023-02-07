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
    int __GetH(TreeNode *root, int &ans) {
        if (root == nullptr)  return 0;
        int lefth = __GetH(root->left, ans);
        int righth = __GetH(root->right, ans);
        ans = max(ans, lefth + righth);
        return max(lefth, righth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        __GetH(root, ans);
        return ans;
    }
};
