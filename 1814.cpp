class Solution {
public:
    const int P = 1e9 + 7;
    int rev(int x) {
        int ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
    long long getAns(long long x) {
        --x;
        return (1 + x) * x / 2;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            ++mp[nums[i] - rev(nums[i])];
        }
        long long ans = 0;
        for (auto i = mp.begin(); i != mp.end(); ++i) {
            ans = (ans + getAns(i->second)) % P;
        }
        return ans;
    }
};
