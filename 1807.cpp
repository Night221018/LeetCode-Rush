class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (int i = 0; i < knowledge.size(); ++i) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans, t;
        bool flag = false;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '(') {
                flag = true;
                continue;
            }
            if (s[i] == ')') {
                if (mp.count(t))  ans += mp[t];
                else  ans += '?';
                t = "";
                flag = false;
                continue;
            }
            if (flag)  t += s[i];
            else  ans += s[i];
        }
        return ans;
    }
};
