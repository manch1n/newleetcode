https : //leetcode-cn.com/problems/get-maximum-in-generated-array/

        class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        vector<int> numBuf(n + 1);
        numBuf[1] = 1;
        int i = 1;
        int maxNum = 1;
        while (1)
        {
            if (i * 2 < n + 1)
            {
                numBuf[i * 2] = numBuf[i];
                maxNum = std::max(numBuf[i * 2], maxNum);
            }
            else
                break;
            if (i * 2 + 1 < n + 1)
            {
                numBuf[i * 2 + 1] = numBuf[i] + numBuf[i + 1];
                maxNum = std::max(numBuf[i * 2 + 1], maxNum);
            }
            else
                break;
            ++i;
        }
        return maxNum;
    }
};