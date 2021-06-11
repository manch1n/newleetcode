// You are given two binary trees root1 and root2.

// Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

// Return the merged tree.

// Note: The merging process must start from the root nodes of both trees.

//  

// Example 1:

// Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
// Output: [3,4,5,5,4,null,7]
// Example 2:

// Input: root1 = [1], root2 = [1,2]
// Output: [2,2]
//  

// Constraints:

// The number of nodes in both trees is in the range [0, 2000].
// -104 <= Node.val <= 104

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/merge-two-binary-trees
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *_dfs(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
            return nullptr;
        TreeNode *n = new TreeNode;
        if (t1 != nullptr && t2 != nullptr)
        {
            n->val = t1->val + t2->val;
            n->left = _dfs(t1->left, t2->left);
            n->right = _dfs(t1->right, t2->right);
        }
        else if (t1 != nullptr && t2 == nullptr)
        {
            n->val = t1->val;
            n->left = _dfs(t1->left, nullptr);
            n->right = _dfs(t1->right, nullptr);
        }
        else if (t1 == nullptr && t2 != nullptr)
        {
            n->val = t2->val;
            n->left = _dfs(nullptr, t2->left);
            n->right = _dfs(nullptr, t2->right);
        }
        return n;
    }
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return _dfs(root1, root2);
    }
};