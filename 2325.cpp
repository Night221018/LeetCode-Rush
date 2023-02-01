class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        char ind = 'a';
        for (int i = 0; key[i]; ++i) {
            if (mp.count(key[i]) || key[i] == ' ')  continue;
            mp[key[i]] = ind++;
        }
        string ans;
        for (int i = 0; message[i]; ++i) {
            if (message[i] == ' ') {
                ans += ' ';
                continue;
            }
            ans += mp[message[i]];
        }
        return ans;
    }
};
