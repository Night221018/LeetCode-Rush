class Solution {
public:
    char repeatedCharacter(string s) {
        int flag = 0;
        for (int i = 0; s[i]; ++i) {
            int ind = s[i] - 'a';
            if (flag & (1 << ind))  return s[i];
            flag |= 1 << ind;
        }
        return '@';
    }
};
