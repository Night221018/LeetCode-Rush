class Solution {
public:
    bool areNumbersAscending(string s) {
        s += " ";
        string t;
        bool flag = true;
        int fro = INT32_MIN;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == ' ') {
                if (flag) {
                    if (stoi(t) <= fro)  return false;
                    else  fro = stoi(t);
                } 
                t = "";
                flag = true;
                continue;
            }
            if (!(s[i] >= '0' && s[i] <= '9'))  flag = false;
            t += s[i];
        }
        return true;
    }
};
