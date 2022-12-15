class Solution {
public:
    string change(string &str) {
        int ans = 0;
        for (int i = 0; str[i]; ++i) {
            ans += str[i] - '0';
        }
        return to_string(ans);
    }
    int getLucky(string s, int k) {
        string ans;
        for (int i = 0; s[i]; ++i) {
            ans += to_string(s[i] - 'a' + 1);
        }
        for (int i = 1; i <= k; ++i) {
            ans = change(ans);
        }
        return stoi(ans);
    }
};
