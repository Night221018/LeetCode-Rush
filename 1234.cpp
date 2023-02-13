class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; s[i]; ++i) {
            ++mp[s[i]];
        }
        int n = s.size() / 4, diff = 0;
        #define JUDGE(letter) { \
            if (mp[letter] > n) { \
                ++diff; \
                mp[letter] -= n; \
            } else mp[letter] = 0; \
        }
        JUDGE('Q');JUDGE('W');JUDGE('E');JUDGE('R');
        if (diff == 0)  return 0;
        int ans = INT32_MAX, left = 0;
        for (int i = 0; s[i]; ++i) {
            --mp[s[i]];
            if (mp[s[i]] == 0) {
                --diff;    
                while (diff == 0) {
                    cout << i << " " << left << " " << diff << endl;
                    ans = min(ans, i - left + 1);
                    ++mp[s[left]];
                    cout << mp[s[left]] << endl;
                    if (mp[s[left]] == 1)  ++diff;
                    ++left;
                } 
            }
            
        }
        return ans;
    }
};
