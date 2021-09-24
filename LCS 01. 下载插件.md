https://leetcode-cn.com/problems/Ju9Xwi/

##### 二叉树及剪枝（超时）
```c++
class Solution {
public:
    int minTime=std::numeric_limits<int>::max();
    int leastMinutes(int n) {
        drive(n,n,1,0);
        return minTime;
    }

    void drive(const int n,int left,int bandwidth,int minute)
    {
        if(minute>=minTime)
        {
            return;
        }
        if(left<=0)
        {
            minTime=std::min(minute,minTime);
            return;
        }
        else if(left<bandwidth)
        {
            minTime=std::min(minute+1,minTime);
            return;
        }
        drive(n,left-bandwidth,bandwidth,minute+1);
        drive(n,left,bandwidth*2,minute+1);
    }
};
```

##### 动态规划写法：
在i/2时选择加倍时间
```c++
class Solution {
public:
    int minTime=std::numeric_limits<int>::max();
    int leastMinutes(int n) {
        vector<int> dp(n+1);
        dp[1]=1;
        for(int i=2;i<=n;++i){
            dp[i]=1+min(dp[i-1], dp[(i+1)/2]);
        }
        return dp[n];
    }
};
```