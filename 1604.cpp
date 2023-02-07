class Solution {
public:
    int GetI(string &str) {
        string t;
        t = t + str[0] + str[1] + str[3] + str[4];
        return stoi(t);
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < keyName.size(); ++i) {
            int t = GetI(keyTime[i]);
            mp[keyName[i]].push_back(t);
        }
        vector<string> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            for (int i = 2; i < it->second.size(); ++i) {
                // cout << it->second[i] << " ";
                if (it->second[i] - it->second[i - 2] <= 100) {
                    ans.push_back(it->first);
                    break;
                }
            }
            // cout << endl;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
