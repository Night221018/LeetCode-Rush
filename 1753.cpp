class Solution {
public:
    void mysort(int &a, int &b, int &c) {
        if (a > b)  swap(a, b);
        if (a > c)  swap(a, c);
        if (b > c)  swap(b, c);
        return ;
    }
    int maximumScore(int a, int b, int c) {
        mysort(a, b, c);
        if (a + b <= c)   return a + b;
        return ((a + b - c) >> 1) + c;
    }
};

/*
先将三堆石子排序，小->大

a + b <= c  答案就是c  从a、b中拿一个和c组队

a + b > c 
想要局数最多就要把c全部用掉，a+b比c多的部分就要考虑内耗
sub = a+b-c  多余的石子 / 2 轮让a、b玩
因为a一定 >= sub (b==c时，a==sub。b<c时，a>sub)
所以答案为内耗的轮数+c
*/
