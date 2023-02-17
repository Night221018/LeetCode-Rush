class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefixsum(m + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 1;i <= m;++i) {
            for (int j = 1;j <= n;++j) {
                prefixsum[i][j] = prefixsum[i - 1][j] + prefixsum[i][j - 1] - prefixsum[i - 1][j - 1] + grid[i - 1][j - 1];
                if (grid[i - 1][j - 1] != 1) continue;
                for (int k = 1;i - k >= 0 && j - k >= 0;++k) {
                    int s1 = prefixsum[i][j] - prefixsum[i - k][j] - prefixsum[i][j - k] + prefixsum[i - k][j - k];
                    int s2 = prefixsum[i - 1][j - 1] - prefixsum[i - k + 1][j - 1] - prefixsum[i - 1][j - k + 1] + prefixsum[i - k + 1][j - k + 1];
                    int t = k - 2;
                    if (s1 - s2 == k * k - t * t) ans = max(ans, k * k);
                }
            }
        }
        return ans;
    }
};
