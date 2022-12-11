/*
注意：题目中给的示例图比例不对！！！容易误解

先拿两块举例
首先只有上层长宽高都 小于等于 下层长宽高时，才能叠放一起。从而得到一个结论两个块如果可以都平着叠放，那一定也可以都立着叠放。(立着就是以最高边作为高)
并且只有两块都立着得到的最终高度最高

所以两个块是否可以堆叠起来是个定性，一旦确定可以堆叠，都平着或者都立着都可以，但是都立着总高度最高

平着放又分为两种情况，长对宽&宽对长 或者 长对长&宽对宽。两种情况都不影响总高度。
但是注意长对宽&宽对长可以叠放的情况，那么长对长&宽对宽也一定满足。
所以求解时把所以块按照长宽高一个方向拜访即可

解法：
旋转每个块，以最长边作为高(全部立起来)，并所有的长宽都按照一个方向摆正。
按照主关键字高，次关键字长，次次关键字宽 从小到大排序。
这样就保证了后边的块一定不能放到前边块的上边。前边的块有概率放到后边块的上边(高肯定都满足，要看长和宽)(两个完全相等块情况除外，谁前谁后一样)
问题转化为了最长上升子序列，只不过可连接条件为前者长宽均小于等于后者
*/

bool cmp(vector<int> &v1, vector<int> &v2) {
    if (v1[2] != v2[2])  return v1[2] < v2[2];
    if (v1[1] != v2[1])  return v1[1] < v2[1];
    return v1[0] < v2[0];
}

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (int i = 0; i < cuboids.size(); ++i) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end(), cmp);
        int ans = 0, *nums = (int *)malloc(sizeof(int) * cuboids.size());
        for (int i = 0; i < cuboids.size(); ++i) {
            nums[i] = cuboids[i][2];
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][0] > cuboids[i][0] || cuboids[j][1] > cuboids[i][1]) {
                    continue;
                }
                if (nums[j] + cuboids[i][2] > nums[i]) {
                    nums[i] = nums[j] + cuboids[i][2];
                }
            }
            ans = max(ans, nums[i]);
        }
        free(nums);
        return ans;
    }
};
