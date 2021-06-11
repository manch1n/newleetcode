// Given a sorted (increasing order) array with unique integer elements, write an algo­rithm to create a binary search tree with minimal height.

// Example:

// Given sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5]，which represents the following tree:

//           0
//          / \ 
//        -3   9
//        /   /
//      -10  5

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-height-tree-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *_bst(const vector<int> &nums, int left, int right)
    {
        if (left > right || left < 0 || right < 0)
            return nullptr;
        else if (left < right)
        {
            int mid = (left + right) / 2;
            TreeNode *n = new TreeNode;
            n->val = nums[mid];
            n->left = _bst(nums, left, mid - 1);
            n->right = _bst(nums, mid + 1, right);
            return n;
        }
        else if (left == right)
        {
            TreeNode *n = new TreeNode;
            n->val = nums[left];
            n->left = nullptr;
            n->right = nullptr;
            return n;
        }
        return nullptr;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;
        return _bst(nums, 0, nums.size() - 1);
    }
};