/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)  return "";
        return to_string(root->val) + "(" + serialize(root->left) + "," + serialize(root->right) + ")";  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<TreeNode *> s;
        TreeNode *ans = nullptr;
        bool flag_r = false;
        string str;
        for (int i = 0; data[i]; ++i) {
            if (data[i] == '(') {
                TreeNode *root = new TreeNode(stoi(str));
                if (!s.empty()) {
                    if (flag_r)  s.top()->right = root;
                    else  s.top()->left = root;
                } else  ans = root;
                s.push(root);
                flag_r = false;
                str = "";
            } else if (data[i] == ')') {
                s.pop();
            } else if (data[i] == ',') {
                flag_r = true;
                str = "";
            } else str += data[i];
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
