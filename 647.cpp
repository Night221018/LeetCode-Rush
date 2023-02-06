class Solution {
public:
    string ns(string s) {
        string t = "#";
        for (int i = 0; s[i]; ++i) {
            (t += s[i]) += '#';
        }
        return t;
    }
    int countSubstrings(string s) {
        string str = ns(s);
        int ans = 0;
        int *r = (int *)calloc(sizeof(int), str.size()), c = 0;
        for (int i = 1; str[i]; ++i) {
            if (i < c + r[c])  r[i] = min(r[2 * c - i], c + r[c] - i);
            while (i - r[i] >= 0 && str[i - r[i]] == str[i + r[i]])  ++r[i];
            --r[i];
            if (i + r[i] > c + r[c])  c = i;
            if (i & 1)  ans += r[i] / 2 + 1;
            else  ans += r[i] / 2;
        }
        return ans;
    }
};
