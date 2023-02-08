class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        int n = p.size(), left = 0, diff = 0;
        for (int i = 0; p[i]; ++i) {
            ++mp[p[i]];
            if (mp[p[i]] == 1)  ++diff;
        }

        vector<int> ans;
        for (int i = 0; s[i]; ++i) {
            if (i >= n) {
                ++mp[s[left]];
                if (mp[s[left]] == 1)  ++diff;
                ++left;
            } 
            --mp[s[i]];
            if (mp[s[i]] == 0)  --diff;
            if (diff == 0)  ans.push_back(i - n + 1);
        }
        return ans;
    }
};
