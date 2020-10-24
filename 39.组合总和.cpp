/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (71.42%)
 * Likes:    981
 * Dislikes: 0
 * Total Accepted:    170.1K
 * Total Submissions: 238K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 * 
 * 
 */
//回溯 剪枝
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size()==0) return ans;
        vector<int> pol;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, pol, ans);
        return ans;

    }

    
    void dfs(vector<int>& candidates, int target, int start, vector<int>& pol, vector<vector<int>>& ans){
        if(target==0)
        {
            ans.push_back(pol);
            return;
        }
        if(target<0)
        {
            return;
        }
        for(int i=start;i<candidates.size();i++){  //i start from 'start' instead of int i=0; which means it start from 0;
            pol.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, pol, ans);
            pol.pop_back();
        }
    }   
};
// @lc code=end
//https://pan.baidu.com/s/1kyQnW86IoKXvlCusMJ0c-g
