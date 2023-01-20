class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_map<int, bool> > mp;
        unordered_map<int, int> cnt;
        for (int i = 0; i < logs.size(); ++i) {
            if (mp[logs[i][0]][logs[i][1]])  continue;
            mp[logs[i][0]][logs[i][1]] = true;
            ++cnt[logs[i][0]];
        }
        vector<int> ans(k);
        for (auto i = cnt.begin(); i != cnt.end(); ++i) {
            ++ans[i->second - 1];
        }
        return ans;
    }
};
