// Given two strings s and t, check if s is a subsequence of t.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

//  

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false
//  

// Constraints:

// 0 <= s.length <= 100
// 0 <= t.length <= 104
// s and t consist only of lowercase English letters.
//  

// Follow up: If there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/is-subsequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        string::size_type lastIndex = 0;
        for (char c : s)
        {
            lastIndex = t.find_first_of(c, lastIndex);
            if (lastIndex == string::npos)
            {
                return false;
            }
            lastIndex++;
        }
        return true;
    }
};