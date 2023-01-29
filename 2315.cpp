class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0, flag = 1;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '|')  flag = !flag;
            if (s[i] == '*' && flag)  ++ans;
        }
        return ans;
    }
};
