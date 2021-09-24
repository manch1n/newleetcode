https : //leetcode-cn.com/problems/n-th-tribonacci-number/

        class Solution
{
public:
    int tribonacci(int n)
    {
        int fiboStack[4] = {0, 1, 1, 2};
        for (int i = 3; i <= n; ++i)
        {
            fiboStack[i % 4] = fiboStack[(i + 1) % 4] + fiboStack[(i + 2) % 4] + fiboStack[(i + 3) % 4];
        }
        return fiboStack[n % 4];
    }
};