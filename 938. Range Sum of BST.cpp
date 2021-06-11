// //https://leetcode-cn.com/problems/range-sum-of-bst/

// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range[low, high].

//  

//                                                                                   Example 1 :

//     Input : root = [ 10, 5, 15, 3, 7, null, 18 ],
//             low = 7, high = 15 Output : 32 Explanation : Nodes 7, 10, and15 are in the range[7, 15].7 + 10 + 15 = 32. Example 2 :

//     Input : root = [ 10, 5, 15, 3, 7, 13, 18, 1, null, 6 ],
//             low = 6, high = 10 Output : 23 Explanation : Nodes 6, 7, and10 are in the range[6, 10].6 + 7 + 10 = 23.
//  

//                                                                                                                 Constraints :

//     The number of nodes in the tree is in the range[1, 2 * 104]
//         .1 <= Node.val <= 105 1 <= low <= high <= 105 All Node.val are unique.

//                                                                                                                 来源：力扣（LeetCode） 链接：https : //leetcode-cn.com/problems/range-sum-of-bst
//                                                                                                                                                      著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
    int sum = 0;
    void _bst(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return;
        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
        }
        _bst(root->left, low, high);
        _bst(root->right, low, high);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        _bst(root, low, high);
        int ret = sum;
        sum = 0;
        return ret;
    }
};