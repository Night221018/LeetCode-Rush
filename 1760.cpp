class Solution {
public:
    bool judge(vector<int> nums, int mid, int maxo) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt += (nums[i] / mid) + !!(nums[i] % mid) - 1;
        }
        return cnt <= maxo;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = 0, mid;
        for (int i = 0; i < nums.size(); ++i) {
            right = max(right, nums[i]);
        }
        while (left < right) {
            mid = ((right - left) >> 1) + left;
            if (judge(nums, mid, maxOperations))  right = mid;
            else  left = mid + 1;
        }
        return right;
    }
};
