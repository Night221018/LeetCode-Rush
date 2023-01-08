class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = (int)pref.size(), ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() < n)  continue;
            string t = words[i].substr(0, n);
            ans += (t == pref);
        }
        return ans;
    }
};
