/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL ) return true;
        if(root->left == NULL && root->right == NULL) return true;
        int left = maxDepth(root->left), right = maxDepth(root->right);
        return abs(left-right)<=1?isBalanced(root->left) && isBalanced(root->right):false;
    }

    //即左右两棵树的最大高度差小于2即可。然后不断向下递归，每棵树都这样的。上述代码最后一句的左边就是这个递归。
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
// @lc code=end

