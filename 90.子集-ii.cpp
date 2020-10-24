/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (61.07%)
 * Likes:    326
 * Dislikes: 0
 * Total Accepted:    53.8K
 * Total Submissions: 87.8K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */


//https://leetcode-cn.com/problems/subsets/solution/c-zong-jie-liao-hui-su-wen-ti-lei-xing-dai-ni-gao-/
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        vector<int> path;
        //是否需要剪枝  先排序
        sort(nums.begin(), nums.end());
        backTracking(ans, nums, 0, path);
        return ans;
    }
    void backTracking(vector<vector<int>> &ans, vector<int> &nums, int start, vector<int>& path)
    {
        ans.push_back(path);
        for(int i=start;i<nums.size();i++)
        {
            //i=start的时候是第一次 无选择不需判读 
            //i>start的时候要选择判断是否和之前一样
            if(i>start && nums[i]==nums[i-1])   //剪枝去重
                continue;
            path.push_back(nums[i]);
            backTracking(ans, nums, i+1, path);
            path.pop_back();
        }
    }
};
// @lc code=end

