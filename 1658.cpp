class Solution {
public:
    int b_search(vector<int> &nums, int left, int right, int x) {
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (nums[mid] == x)  return mid;
            if (nums[mid] > x)  right = mid - 1;
            else  left = mid + 1;
        }
        return INT32_MAX;
    }
    int minOperations(vector<int>& nums, int x) {
        vector<int> pex(nums.size());
        pex[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pex[i] = pex[i - 1] + nums[i];
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            nums[i] += nums[i + 1];
        }
        nums.push_back(0);
        int ans = INT32_MAX;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] == x) {
                ans = min(ans, (int)nums.size() - i - 1);
                break;
            }
            int t = b_search(pex, 0, i - 1, x - nums[i]);
            if (t >= i)  continue;
            ans = min(ans, t + (int)nums.size() - i);
        }
        return (ans == INT32_MAX ? -1 : ans);
    }
};
