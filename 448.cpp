class Solution {
public:
    bool GoHome(int ind, vector<int> &nums) {
        while (nums[ind] != ind + 1) {
            if (nums[nums[ind] - 1] == nums[ind])  return false;
            swap(nums[nums[ind] - 1], nums[ind]);
        }
        return true;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            GoHome(i, nums);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums[i] - 1)  ans.push_back(i + 1);
        }
        return ans;
    }
};
