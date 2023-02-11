class Solution {
public:
    int fillCups(vector<int>& nums) {
        if (nums[0] > nums[1])  swap(nums[0], nums[1]);
        if (nums[0] > nums[2])  swap(nums[0], nums[2]);
        if (nums[1] > nums[2])  swap(nums[1], nums[2]);
        int a = nums[0], b = nums[1], c = nums[2];
        if (c >= a + b)  return c;
        int ans = 0;
        b -= a;
        c -= b;
        ans += b;
        int d = c & 1;
        a -= c >> 1;
        ans += (c >> 1 << 1) + a + d;
        return ans;
    }
};
