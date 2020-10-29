/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (48.04%)
 * Likes:    629
 * Dislikes: 0
 * Total Accepted:    44.8K
 * Total Submissions: 92.7K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m,vector<int> (n));
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(matrix[i][j]=='1') {
              if(j==0) dp[i][j]=1;
              else dp[i][j] = dp[i][j-1]+1;
            }
            else dp[i][j]=0;

            int min_width = dp[i][j];
            for(int col=i;col>=0;col--){
              int hi = i-col+1;
              min_width = min(min_width, dp[col][j]);
              ans = max(ans, min_width*hi);
          }
          }
          
        }
        return ans;
    }
};
// @lc code=end

