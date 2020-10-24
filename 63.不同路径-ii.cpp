/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (36.77%)
 * Likes:    424
 * Dislikes: 0
 * Total Accepted:    105.2K
 * Total Submissions: 285.2K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */

// @lc code=start

//只要把障碍地点的方法数设置为0即可。
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        if(m==0) return 0;  //判空直接返回0
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));//
        dp[0][0] = !obstacleGrid[0][0];
        if(!dp[0][0]) return 0;  //入口有障碍直接返回0
        
        //卧槽 之前出错在for循环 草。。。
        //判断条件只要不满足就会退出for循环啊。。。
        //而不是这次跳过(相当于continue) 然后i++。。。
        //我傻逼了 没事了
        for(int i=0;i<n && obstacleGrid[0][i]==0;i++)
        {
            dp[0][i] = 1;
        }
        for(int j=0;j<m && obstacleGrid[j][0]==0;j++)
        {
            dp[j][0] = 1;
        }
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                if(!obstacleGrid[i][j]) 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else dp[i][j] = 0;
        //return dp[0][2];
        return dp[m-1][n-1];
    }
};
// @lc code=end

