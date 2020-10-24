/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return midSort(nums, 0, nums.size()-1);
    }
    TreeNode* midSort(vector<int>& nums, int l, int r){
        if(l>r) return NULL;
        int mid = l + ((r-l)>>1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = midSort(nums, l, mid-1);
        root->right = midSort(nums, mid+1, r);
        return root;
    }
};
// @lc code=end

