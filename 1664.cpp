class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd_f, odd_b, even_f, even_b, ans;
        odd_f = odd_b = even_f = even_b = ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1)  odd_b += nums[i];
            else  even_b += nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1)  odd_b -= nums[i];
            else  even_b -= nums[i];
            
            if (odd_f + even_b == odd_b + even_f)  ++ans;
            
            if (i & 1)  odd_f += nums[i];
            else  even_f += nums[i];
        }
        return ans;
    }
};
