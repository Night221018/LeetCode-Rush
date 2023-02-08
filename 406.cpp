bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] != b[0])  return a[0] > b[0];
    return a[1] < b[1];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        for (int i = 1; i < people.size(); ++i) {
            for (int j = i; people[j][1] < j; --j) {
                swap(people[j], people[j - 1]);
            }
        }
        return people;
    }
};
