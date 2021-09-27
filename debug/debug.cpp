#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <list>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        string &minStr = word1;
        string &largeStr = word2;
        if (word1.size() > word2.size())
        {
            minStr = word2;
            largeStr = word1;
        }
        int minstep = std::numeric_limits<int>::max();
        for (int i = 0; i < minStr.size(); ++i)
        {
            for (int j = i + 1; j <= minStr.size(); ++j)
            {
                auto pattern = string(minStr.begin() + i, minStr.begin() + j);
                if (largeStr.find(pattern) != string::npos)
                {
                    int thisStep = minStr.size() - pattern.size() + largeStr.size() - pattern.size();
                    minstep = std::min(thisStep, minstep);
                }
            }
        }
        return minstep;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    int ans = s.minDistance("leetcode", "etco");
    return 0;
}
