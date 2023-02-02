struct Node {
    int now, step, color;
};

class Solution {
public:
    void init_mp(vector<vector<int>>& Edges, unordered_map<int, vector<int> > &mp) {
        for (int i = 0; i < Edges.size(); ++i) {
            mp[Edges[i][0]].push_back(Edges[i][1]);
        }
        return ;
    }
    void __BFS(Node &temp, vector<int> &edg, int *flag, vector<int> &ans, queue<Node> &que) {
        int clr = !temp.color;
        for (int i = 0; i < edg.size(); ++i) {
            if (flag[edg[i]] & (1 << clr))  continue;
            flag[edg[i]] |= (1 << clr);
            ans[edg[i]] = min(ans[edg[i]], temp.step + 1);
            que.push((Node){edg[i], temp.step + 1, clr});
        }
        return ;
    }
    void BFS(queue<Node> &que, unordered_map<int, vector<int> > mp_r, unordered_map<int, vector<int> > mp_b,
    int *flag,  vector<int> &ans) {
        while (!que.empty()) {
            Node temp = que.front();
            que.pop();
            if (temp.color == 1)  __BFS(temp, mp_b[temp.now], flag, ans, que);
            else  __BFS(temp, mp_r[temp.now], flag, ans, que);
            
        }
        return ;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<int> > mp_r, mp_b;    
        init_mp(redEdges, mp_r);
        init_mp(blueEdges, mp_b);
        
        vector<int> ans(n, INT32_MAX);
        ans[0] = 0;
        
        int *flag = (int *)calloc(sizeof(int), n + 3);
        flag[0] = 3;

        queue<Node> que;
        que.push((Node){0, 0, 1});
        que.push((Node){0, 0, 0});
        
        BFS(que, mp_r, mp_b, flag, ans);
        
        for (int i = 0; i < n; ++i) {
            if (ans[i] == INT32_MAX)  ans[i] = -1;
        }
        free(flag);
        return ans;
    }
};
