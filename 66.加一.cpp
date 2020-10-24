/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.45%)
 * Likes:    550
 * Dislikes: 0
 * Total Accepted:    206.4K
 * Total Submissions: 454.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      if(digits[0]==0)
      {
        digits[0]+=1;
        return digits;
      }
      int isup = 0; //判断是否进位
      int dsize = digits.size();
      const int anssize=dsize+1;
      vector<int>ans(anssize);
      for(int i=dsize-1;i>=0;i--)
      {
        if(isup == 1 || i==dsize-1)
        {
          digits[i] = digits[i]+1;
          ans[i+1] = digits[i];
          isup = 0;
        }
        if(digits[i]>9)
        {
          digits[i] = 0;
          ans[i+1] = 0;
          isup = 1;
        }
      }
      if(isup == 1)
      {
        ans[0] = 1;
        return ans;
      }
      return digits; 
    }
};
// @lc code=end

