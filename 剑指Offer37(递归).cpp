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
        if (root == nullptr)  return "#";
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right); 
    }


    TreeNode* __deserialize(vector<int> &msg, int &ind) {
        if (msg[ind] == INT32_MIN) {
            ++ind;
            return nullptr;
        }
        TreeNode *s = new TreeNode(msg[ind++]);
        s->left = __deserialize(msg, ind);
        s->right = __deserialize(msg, ind);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string t;
        data += ',';
        vector<int> msg;
        for (int i = 0; data[i]; ++i) {
            if (data[i] == ',') {
                if (t == "#")  msg.push_back(INT32_MIN);
                else  msg.push_back(stoi(t));
                t = "";
                continue;
            }
            t += data[i];
        }
        int ind = 0;
        return __deserialize(msg, ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
