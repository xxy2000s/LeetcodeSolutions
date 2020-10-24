/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.87%)
 * Likes:    514
 * Dislikes: 0
 * Total Accepted:    208.3K
 * Total Submissions: 535.8K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {  //注意 相乘的话改成long long形式 否则会溢出
        long long lf = 1;
        long long rf = x/2 + 1;
        while(lf<=rf){
          long long mid = lf + ((rf-lf)>>1);
          if(mid*mid> x)
          {
            rf = mid-1;
          }          
          else if(mid*mid< x)
          {
            lf = mid+1;
          }
          else return mid;
        }
        return rf;
    }
};
// @lc code=end

