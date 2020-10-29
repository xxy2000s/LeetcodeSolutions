/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (67.54%)
 * Likes:    696
 * Dislikes: 0
 * Total Accepted:    152.3K
 * Total Submissions: 225.3K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for(int i=0;i<m;i++)
          for(int j=0;j<n;j++)
            {
              if(i==0)
              {
                if(j==0) continue;
                dp[i][j] = dp[i][j-1] + grid[i][j];
              }
              else if(j==0)
              {
                dp[i][j] = dp[i-1][j] + grid[i][j];
              }
              else
              {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
              }
            }
        return dp[m-1][n-1];
    }
};
// @lc code=end

