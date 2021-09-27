https://leetcode-cn.com/problems/w3tCBm/

```c++
class Solution {
public:
    inline int count(int n)
    {
        int count=0;
        int base=1;
        while(base<=100000)
        {
            if(n&base)
            {
                count++;
            }
            base*=2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;++i)
        {
            res.push_back(count(i));
        }
        return res;
    }
};
```