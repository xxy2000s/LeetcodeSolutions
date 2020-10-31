/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (37.62%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    45.8K
 * Total Submissions: 121.6K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 * 
 * 示例1:
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s1.size()==0) return true;
      if(s2.size()==0) return false;
      int cnt=s1.size();
      int left=0;
      int right=0;
      unordered_map<char, int> dir;
      for(char c:s1) dir[c]++;


      //标准滑动窗口。
      for(;right<s2.size();right++){
        if(--dir[s2[right]]>=0) 
        {
          cnt--;
          if(cnt==0) return true;
        }
        //left指针滑到等于当前值的索引。中途恢复cnt和dir中的数量
        //因为之前自减了，所以要恢复当前值在dir中的数量，然后left指向当前索引的下一个索引 
        else 
        { 
          //突然发现这个if判断不需要 直接简化
          // if(s2[left]==s2[right])
          // {
          //   dir[s2[right]]++;
          //   left++;
          // }
          // else
          // {
         //最终情况是left滑到right位置
          while(s2[left]!=s2[right])
            {
              cnt++;
              dir[s2[left]]++;
              left++;
            }
            //之前一直忘了这句 导致一直出错2333 调试秒解决问题。
            //之前自减了，所以这个不需要的数在dir中存储值应该要恢复0
            dir[s2[left]]++;   //就这句
            left++;
        }
      }
      return cnt==0?true:false;
    }
};
// @lc code=end

