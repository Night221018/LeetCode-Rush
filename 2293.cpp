class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int step = 1;
        while (step - nums.size()) {
            for (int i = 0, j = 1; i < nums.size(); i += step << 1, ++j) {
                if (j & 1)  nums[i] = min(nums[i], nums[i + step]);
                else  nums[i] = max(nums[i], nums[i + step]);
            }
            step <<= 1;
        }
        return nums[0];
    }
};
