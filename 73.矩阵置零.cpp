/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (55.84%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    56.9K
 * Total Submissions: 101.9K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * 
 * 示例 1:
 * 
 * 输入: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * 输出: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * 输出: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 进阶:
 * 
 * 
 * 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个常数空间的解决方案吗？
 * 
 * 
 */

// @lc code=start
//以第一行第一列为标识 这样就是常数空间了
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      if(matrix.size()==0 || matrix[0].size()==0) return;
      int rflg = false;  //第一行是否有0标识
      int cflg = false;  //第一列是否有0标识
      int m = matrix.size();
      int n = matrix[0].size();

      //首先若是第一行或第一列有0 标识就改为true 最后标识为true的对应行或列要全置0
      for(int i=0;i<m;i++)
        if(matrix[i][0] == 0)
        {
            cflg = true;
            break;
        }
      for(int j=0;j<n;j++)
        if(matrix[0][j] == 0)
        {
            rflg = true;
            break;
        }

      //如果i行j列有0 则把对应的第一行位置和第一列位置置0
      //即若matrix[i][j] = 0 
      //则matrix[i][0] = 0, matrix[0][j] = 0
      for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
          if(matrix[i][j] == 0)
          {
              matrix[i][0] = 0;
              matrix[0][j] = 0;
          }

      //将第一行和第一列中有0的位置 其对应的列和行置0
      //这段刚开始没反应过来 是正确的。遍历除第一行第一列的所有行和列 如果对应的第一行或第一列有0 则把当前元素置0
      //即遍历(m-1)*(n-1) 个元素 如果它对应的第一行或者第一列为0 则这个元素被置0 
      for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
          if(matrix[i][0]==0 || matrix[0][j]==0)
            matrix[i][j] = 0;

      //如果最初始第一行或第一列有0 则对应行列置0
      if(cflg)
      {
        for(int i=0;i<m;i++)
          matrix[i][0] = 0;
      }
      if(rflg)
      {
        for(int j=0;j<n;j++)
          matrix[0][j] = 0;
      }
    }
};
// @lc code=end

