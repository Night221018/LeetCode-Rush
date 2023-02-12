class Solution {
public:
    TreeNode* GetM(TreeNode *root, int x) {
        if (root == nullptr || root->val == x)  return root;
        TreeNode *left = GetM(root->left, x);
        if (left)  return left;
        TreeNode *right = GetM(root->right, x);
        return right;
    }

    int GetC(TreeNode *root) {
        if (root == nullptr)  return 0;
        return GetC(root->left) + GetC(root->right) + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *my = GetM(root, x); 
        int a = GetC(my->left);
        int b = GetC(my->right);
        int c = GetC(root) - a - b - 1;
        // cout << a << b << c << endl;
        if (a > b)  swap(a, b);
        if (a > c)  swap(a, c);
        if (b > c)  swap(b, c);
        
        return c > a + b;
    }
};
