class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        for (int i = 0; i < brackets.size(); ++i) {
            if (i == 0)  ans += min(brackets[i][0], income) * (brackets[i][1] / 100.0);
            else  ans += (min(brackets[i][0], income) - brackets[i - 1][0]) * (brackets[i][1] / 100.0);
            if (income <= brackets[i][0])  break;
        }
        return ans;
    }
};
