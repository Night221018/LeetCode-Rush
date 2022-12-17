// 可变长度和内容 的 滑动窗口

class Solution {
public:
    void mpush(vector<vector<int>> &groups, int ind, unordered_map<int, int> &mp, int &diff) {
        for (int i = 0; i < groups[ind].size(); ++i) {
            ++mp[groups[ind][i]];
            if (mp[groups[ind][i]] == 1)  ++diff;
        }
        return ;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int ind = 0, diff = 0;
        unordered_map<int, int> mp;
        mpush(groups, 0, mp, diff);
        int start = 0, dis = groups[0].size();
        for (int i = 0; i < nums.size(); ++i) {
            if (i - dis >= start) {
                ++mp[nums[i - dis]];
                if (mp[nums[i - dis]] == 1)  ++diff;
            }
            --mp[nums[i]];
            if (mp[nums[i]] == 0)  --diff;
            if (diff == 0) {
                mp.clear();
                ++ind;
                if (ind == groups.size())  return true;
                mpush(groups, ind, mp, diff);
                start = i + 1;
                dis = groups[ind].size();
            }
        }
        return false;
    }
};
