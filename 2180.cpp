class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 2; i <= num; ++i) {
            int sum = 0, x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            ans += !(sum & 1);
        }
        return ans;
    }
};
