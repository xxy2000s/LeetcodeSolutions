/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (78.15%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    49.7K
 * Total Submissions: 63.4K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */

//100% runtime 5.28% memory usage
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> ans(n, vector<int>(n,1));
      int u = 0;
      int d = n-1;
      int l = 0;
      int r = n-1;
      while(true){
        for(int i=l;i<=r;i++)
        {
          if(i==0) continue;
          else ans[u][i]+=ans[u][i-1];
        }
        if(++u>d) break;
        for(int i=u;i<=d;i++)
        {
          ans[i][r]+=ans[i-1][r];
        }
        if(--r<l) break;
        for(int i=r;i>=l;i--)
        {
          ans[d][i] += ans[d][i+1];
        }
        if(--d<u) break;
        for(int i=d;i>=u;i--)
        {
          ans[i][l] += ans[i+1][l];
        }
        if(++l>r) break;
      }
      return ans;
    }
};
// @lc code=end

