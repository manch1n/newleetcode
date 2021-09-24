https: //leetcode-cn.com/problems/chuan-di-xin-xi/
##### BFS写法
```c++
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> adjacency(n,vector<int>(n));
        for(auto& pair:relation)
        {
            adjacency[pair[0]][pair[1]]=1;
        }
        return bfs(adjacency,n,0,k);
    }

    int bfs(const vector<vector<int>>& adjacency,const int n, int start,int k)
    {
        if(k==0)
        {
            if(start==n-1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int successPath=0;
        for(int i=0;i<n;++i)
        {
            if(adjacency[start][i]==1)
            {
                successPath+=bfs(adjacency,n,i,k-1);
            }
        }
        return successPath;
    }
}; 
```
##### 动态规划写法
dp[i][j]表示的是通过第i步能到达j的方案数，显然dp[0][0]=1
dp[i][j]=sigma(dp[i-1][k]) k={k->j}
```c++
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> adjacency(n);
        for(auto& pair:relation)
        {
            adjacency[pair[0]].push_back(pair[1]);
        }

        vector<vector<int>> dp(k+1,vector<int>(n));
        dp[0][0]=1;
        for(int i=1;i<=k;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    if(std::find(adjacency[k].begin(),adjacency[k].end(),j)!=adjacency[k].end())
                    {
                        dp[i][j]+=dp[i-1][k];
                    }
                }
            }
        }
        return dp[k][n-1];
    }
}; 
```
