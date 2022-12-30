class ExamRoom {
public:
    map<int, bool> mp;
    int n;
    ExamRoom(int __n) : n(__n) {}
    
    int seat() {
        if (mp.empty()) {
            mp[0] = true;
            return 0;
        }
        map<int, bool>::iterator it = mp.begin();
        auto fro = it;
        ++it;
        int ind = 0, dis = 0;
        while (it != mp.end()) {
            int t = (it->first - fro->first) >> 1;
            if (t > dis) {
                dis = t;
                ind = fro->first + t;
            }
            ++fro;
            ++it;
        }
        int s = mp.begin()->first;
        auto eend = mp.end();
        --eend;
        int e = eend->first;
        if (s != 0 && s >= dis) {   //注意0的优先级最大
            dis = s;
            ind = 0;
        }
        if (e != n - 1 && n - e - 1 > dis) {
            dis = n - e - 1;
            ind = n - 1;
        }
        mp[ind] = true;
        return ind;
    }
    
    void leave(int p) {
        mp.erase(p);
        return ;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
