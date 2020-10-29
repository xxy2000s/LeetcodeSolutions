/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (66.71%)
 * Likes:    628
 * Dislikes: 0
 * Total Accepted:    113.2K
 * Total Submissions: 169.5K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 * 
 * 
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0||triangle[0].size()==0) return 0;
        int m=triangle.size();
        vector<int> dp(m+1,0);  
        //dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        //i 不起作用 说明可以省了
        //自底向上 从下往上推一下就明白了
        for(int i=m-1;i>=0;i--)
            for(int j=0;j<=i;j++)
                dp[j] = min(dp[j],dp[j+1]) +triangle[i][j];
        return dp[0];
    }
};
// @lc code=end

