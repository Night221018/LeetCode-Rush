class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s2.size() > s1.size())  swap(s1, s2);
        vector<string> v1, v2;
        s1 += ' ';
        s2 += ' ';
        string t;
        for (int i = 0; s1[i]; ++i) {
            if (s1[i] == ' ') {
                v1.push_back(t);
                t = "";
            }  else  t += s1[i];
        }
        for (int i = 0; s2[i]; ++i) {
            if (s2[i] == ' ') {
                v2.push_back(t);
                t = "";
            }  else  t += s2[i];
        }

        int l = 0, r = v2.size() - 1, vr = v1.size() - 1;
        
        while (l < v1.size() && l < v2.size() && v1[l] == v2[l])  ++l;
        while (r >= 0 && vr >= 0 && v1[vr] == v2[r])  --r, --vr;
        return l > r;
    }
};
