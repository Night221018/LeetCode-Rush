class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        int k = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == k)  k <<= 1;
            ans.push_back(ans[i - (k >> 1)] + 1);
        }
        return ans;
    }
};
