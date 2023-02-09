struct Node {
    int cnt;
    string str;
};

class Solution {
public:
    string decodeString(string str) {
        stack<Node> s;
        s.push(Node{1, ""});
        string num;
        for (int i = 0; str[i]; ++i) {
            if (str[i] == '[') {
                s.push(Node{stoi(num), ""});
                num = "";
            } else if (str[i] == ']') {
                Node temp = s.top();
                s.pop();
                while (temp.cnt--) {
                    s.top().str += temp.str;
                }
            } else if (str[i] >= 'a' && str[i] <= 'z') {
                s.top().str += str[i];
            } else {
                num += str[i];
            }
        }
        return s.top().str;
    }
};
