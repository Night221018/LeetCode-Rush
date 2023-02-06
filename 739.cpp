class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temper) {
        stack<pair<int, int>> s;
        vector<int> ans(temper.size(), 0);
        for (int i = temper.size() - 1; i >= 0; --i) {
            int t = temper[i];
            while (!s.empty() && s.top().second <= t)  s.pop(); 
            if (!s.empty())  ans[i] = s.top().first - i;
            s.push(make_pair(i, t));
        }
        return ans;
    }
};
