class Solution {
public:
    int reinitializePermutation(int n) {
        int *nums = (int *)malloc(sizeof(int) * n), cnt = 0;
        for (int i = 0; i < n; ++i)  nums[i] = i;
        while (1) {
            ++cnt;
            bool flag = true;
            int *t = (int *)malloc(sizeof(int) * n);
            for (int i = 0; i < n; ++i) {
                if (i & 1)  t[i] = nums[n / 2 + (i - 1) / 2];
                else  t[i] = nums[i / 2];
                if (t[i] - i)  flag = false;
            }
            if (flag)  break;    
            free(nums);
            nums = t;
        }
        return cnt;
    }
};
