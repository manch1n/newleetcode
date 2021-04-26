// //人老了，也不愿意折腾O（1）空间复杂度的解法了

// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

//  

// Example 1:

// Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// Example 2:

// Input: root = [5,1,7]
// Output: [1,null,5,null,7]
//  

// Constraints:

// The number of nodes in the given tree will be in the range [1, 100].
// 0 <= Node.val <= 1000

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/increasing-order-search-tree
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
    TreeNode *lastVisited = nullptr;
    vector<TreeNode *> mnodes;
    void bst(TreeNode *root)
    {
        if (root == nullptr)
            return;
        bst(root->left);
        mnodes.push_back(root);
        bst(root->right);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        bst(root);
        for (int i = 0; i < mnodes.size() - 1; ++i)
        {
            mnodes[i]->left = nullptr;
            mnodes[i]->right = mnodes[i + 1];
        }
        mnodes[mnodes.size() - 1]->left = nullptr;
        mnodes[mnodes.size() - 1]->right = nullptr;
        return mnodes[0];
    }
};