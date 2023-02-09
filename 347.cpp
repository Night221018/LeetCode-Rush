class Solution {
public:
    void quick_search(vector<pair<int, int>> &nums, int left, int right, int k) {
        if (left >= right)  return ;
        int l = left, r = right;
        pair<int, int> mid = nums[r];
        while (l < r) {
            while (l < r && nums[l].second >= mid.second)  ++l;
            if (l < r)  nums[r--] = nums[l];
            while (l < r && nums[r].second <= mid.second)  --r;
            if (l < r)  nums[l++] = nums[r];
        }
        nums[l] = mid;
        if (l == k)  return ;
        if (k > l)  quick_search(nums, l + 1, right, k);
        else  quick_search(nums, left, r - 1, k);
        return ;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            ++mp[nums[i]];
        }
        vector<pair<int, int>> vec;
        vec.push_back(make_pair(0, 0));
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            vec.push_back(make_pair(it->first, it->second));
        }
        quick_search(vec, 1, vec.size() - 1, k);
        vector<int> ans;
        for (int i = 1; i <= k; ++i) {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
