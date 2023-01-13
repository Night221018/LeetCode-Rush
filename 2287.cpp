class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; target[i]; ++i)  ++mp2[target[i]];
        for (int i = 0; s[i]; ++i)  ++mp1[s[i]];
        int ans = INT32_MAX;
        for (char i = 'a'; i <= 'z'; ++i) {
            if (!mp2.count(i))  continue;
            ans = min(ans, mp1[i] / mp2[i]);
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};
