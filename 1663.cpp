class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for (int i = 1; i <= n; i++) {
            int lower = max(1, k - (n - i) * 26);
            k -= lower;
            ans.push_back('a' + lower - 1);
        }
        return ans;
    }
};
