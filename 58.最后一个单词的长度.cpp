/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (33.70%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    127.4K
 * Total Submissions: 378K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
      if(s.size()==0)
      {
        return 0;
      }
      int ans = 0;
      int result = 0;
      int ssize = s.size();
      for(int i=0; i<ssize;i++){
        if(s[i]!=' ')
        {
          ans++;
          result = ans;
        }
        else
        {
          ans = 0;
        }
      }
      return result;
    }
};
// @lc code=end

