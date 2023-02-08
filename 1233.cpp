struct Node {
    Node() : flag(false) {}
    bool flag;
    string val;
    unordered_map<string, Node *> mp;
};

class Solution {
public:
    string getstr(int &ind, string &str) {
        string t;
        while (str[ind] != '/') {
            t += str[ind++];
        }
        ++ind;
        return t;
    }
    Node* build(Node *root, int &ind, string str) {
        if (root == nullptr)  root = new Node();
        if (ind == str.size()) {
            root->flag = 1;
            root->val = str;
            root->val[root->val.size() - 1] = '\0';
            return root;
        }
        string t;
        t = getstr(ind, str);
        // if (!root->mp.count(t))  root->mp[t] = nullptr;
        root->mp[t] = build(root->mp[t], ind, str);
        return root;
    }
    void getAns(Node *root, vector<string> &ans) {
        if (root->flag) {
            ans.push_back(root->val);
            return ;
        }
        for (auto it = root->mp.begin(); it != root->mp.end(); ++it) {
            getAns(it->second, ans);
        }
        return ;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        Node *root = nullptr;
        for (int i = 0; i < folder.size(); ++i) {
            int ind = 1;
            root = build(root, ind, folder[i] + '/');
        }
        getAns(root, ans);
        return ans;
    }
};
