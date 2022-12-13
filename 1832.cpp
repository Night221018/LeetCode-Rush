class Solution {
public:
    bool checkIfPangram(string sentence) {
        char offset[26] = {false};
        int cnt = 0;
        for (int i = 0; sentence[i]; ++i) {
            if (offset[(int)(sentence[i] - 'a')] == true)  continue;
            offset[(int)(sentence[i] - 'a')] = true;
            ++cnt;
        }
        return cnt == 26;
    }
};
