/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (35.80%)
 * Likes:    4514
 * Dislikes: 0
 * Total Accepted:    707.8K
 * Total Submissions: 2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();

        //用滑动窗口来实现
        // int ans=0;
        // int left=0;
        // unordered_set<char> lookup;
        // for(int i=0;i<s.size();i++){
        //   //找到了s[i]在lookup中 则要删最左元素
        //   while(lookup.find(s[i]) != lookup.end())
        //   {
        //     lookup.erase(s[left]);
        //     left++;
        //   }
        //   if(ans<(i-left+1))
        //     ans = i-left+1;
        //   lookup.insert(s[i]);
        // }
        // return ans;

        //用map来实现
        //从头开始的双指针
        //start标记开始 end循环变量
        //map中无重复对象则一直往后走end。并添加键值对(s[end],end+1)
        //end+1为方便更新为start 即新的开头。
        //有重复对象则更新start 为s[end]在map中的索引后一位 而s[end]的值为索引+1
        //则start = lookup.find(s[end])->second
        //清除键值对
        int ans =0;
        int start=0;
        int end = 0;
        map<char,int> lookup;
        for(;end<s.size();end++){
          if(lookup.find(s[end]) != lookup.end())  //s[end]在lookup中
          {
            int tmp = lookup.find(s[end])->second;
            if(start<tmp)
              start = tmp;
            lookup.erase(s[end]);//map的insert方法忽略重复key。而非替换所以要erase之前的key
          }
          if(ans<end-start+1)
            ans = end-start+1;
          //要插入键值对。用pair类型
          lookup.insert(pair<char,int>(s[end], end+1));  
        }
        return ans;
    }
};
// @lc code=end

