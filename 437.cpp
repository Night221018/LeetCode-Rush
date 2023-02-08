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
    unordered_map<long long, int> mp;
    int __pathSum(TreeNode *root, int targetSum, long long fat) {
        if (root == nullptr)  return 0;
        int cnt = mp[root->val + fat - targetSum];
        ++mp[root->val + fat];
        cnt += __pathSum(root->left, targetSum, root->val + fat);
        cnt += __pathSum(root->right, targetSum, root->val + fat);
        --mp[root->val + fat];
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return __pathSum(root, targetSum, 0);
    }
};
