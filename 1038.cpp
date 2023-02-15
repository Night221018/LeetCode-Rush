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
