/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (79.04%)
 * Likes:    842
 * Dislikes: 0
 * Total Accepted:    161.9K
 * Total Submissions: 204.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
// ①画出递归树，找到状态变量(回溯函数的参数)，这一步非常重要※
// ②根据题意，确立结束条件
// ③找准选择列表(与函数参数相关),与第一步紧密关联※
// ④判断是否需要剪枝
// ⑤作出选择，递归调用，进入下一层
// ⑥撤销选择

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        vector<int> path;
        backTracking(ans, nums, 0, path);
        return ans;
    }

    void backTracking(vector<vector<int>>&ans,vector<int>&nums, int index, vector<int>&path)
    {
        ans.push_back(path);
        for(int i=index;i<nums.size();i++)
        {
            path.push_back(nums[i]);//进行选择 
            backTracking(ans, nums, i+1, path); //选择了nums[i] 则接着进行后面的回溯操作
            path.pop_back(); //撤销操作 再进行后面的回溯操作
        }
        
    }
};
// @lc code=end

