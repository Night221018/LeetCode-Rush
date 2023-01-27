class Solution {
public:
    string greatestLetter(string s) {
        string ans = "";
        int up = 0, low = 0;
        for (int i = 0; s[i]; ++i) {
            int ind;
            if (s[i] > 'Z') {
                ind = s[i] - 'a';
                low |= 1 << ind;
            } else {
                ind = s[i] - 'A';
                up |= 1 << ind;
            }
            if ((up & (1 << ind)) & (low & (1 << ind))) {
                string t = "A";
                t[0] += ind;
                if (ans == "")  ans = t;
                else  ans = (ans[0] > t[0]) ? ans : t;
            }  
        }
        return ans;
    }
};
