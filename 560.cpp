class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        if (nums[0] == k)  ++ans;
        ++mp[0];
        ++mp[nums[0]];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
            ans += mp[nums[i] - k];
            ++mp[nums[i]];
        }
        return ans;
    }
};
