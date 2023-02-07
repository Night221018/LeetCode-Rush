class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int ans = 0;
        while (x) {
            x -= x & -x;
            ++ans;
        }
        return ans;
    }
};
