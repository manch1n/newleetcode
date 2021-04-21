// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
//  

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
// Example 4:

// Input: s = "([)]"
// Output: false
// Example 5:

// Input: s = "{[]}"
// Output: true
//  

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-parentheses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool isValid(string s) {
        stack<char> cstack;
        unordered_map<char,char> m;
        m['(']=')';
        m['{']='}';
        m['[']=']';
        for(auto c:s)
        {
            if(c=='('||c=='{'||c=='[')
            {
                cstack.push(c);
            }
            else
            {
                if(cstack.size()==0) return false;
                auto t=cstack.top();
                if(m[t]!=c) return false;
                cstack.pop();
            }
        }
        if(cstack.size()>0) return false;
        else return true;
    }
};