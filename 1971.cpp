class Solution {
public:
    int getf(vector<int> &far, int x) {
        if (x == far[x])  return x;
        return far[x] = getf(far, far[x]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> far(n);
        for (int i = 1; i < n; ++i)  far[i] = i;
        for (int i = 0; i < edges.size(); ++i) {
            int sf = getf(far, edges[i][0]);
            int ef = getf(far, edges[i][1]);
            if (sf - ef) {
                far[sf] = ef;
            }
        }
        return getf(far, source) == getf(far, destination);
    }
};
