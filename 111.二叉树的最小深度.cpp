/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        
        if(root == NULL) return 0;
        int left = minDepth(root->left), right = minDepth(root->right);
        return (left && right)?1+min(left,right):1+left+right;  //实际上只有一颗子树的情况对应右边。核心思想在这。
        //刚开始只考虑了左边的情况。所以【1，2】这种情况会出错。考虑只有一颗子树的情况就可以如上述右边条件。

    }
};
// @lc code=end

