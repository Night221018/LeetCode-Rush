class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)  sum += nums[i];
        if (sum & 1)  return false;
        sum >>= 1;
        vector<bool> flag(sum + 1, false);
        flag[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum; j > 0; --j) {
                if (flag[j])  continue;
                if (j - nums[i] >= 0 && flag[j - nums[i]])  flag[j] = true;
            }
        }
        return flag[sum];
    }
};
