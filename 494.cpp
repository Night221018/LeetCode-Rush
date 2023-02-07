class Solution {
public:
    int __find(vector<int> &nums, int ind, int target) {
        if (ind == nums.size())  return target == 0;
        return __find(nums, ind + 1, target + nums[ind]) + __find(nums, ind + 1, target - nums[ind]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return __find(nums, 0, target);
    }
};
