/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (39.50%)
 * Likes:    806
 * Dislikes: 0
 * Total Accepted:    85.9K
 * Total Submissions: 217.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：S = "ADOBECODEBANC", T = "ABC"
 * 输出："BANC"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        //需要匹配的数组t用unordered_map,查找O(1), 其实如果知道是字母用vector完全够用，但map可拓展性更强一些。而普通的map是有序二叉树结构，需要二分查找O(log2(n)),不适用于反复进行读取数组的情况。

        if(s.size()==0 || t.size()==0) return "";
        unordered_map<char,int> dir;
        //two-pointer 遍历 end为循环变量
        int left=0,end=0;
        int cnt=0;   //是否找到计数
        int start=-1;  //start判断是否存在子串
        int ans=s.size();
        for(char c:t) dir[c]++;
        for(;end<s.size();end++){
            if(--dir[s[end]]>=0) cnt++;  
            while(cnt == t.size())
            {
                if(ans>=end-left+1)
                {
                    ans = end-left+1;  //字串长度
                    start = left;  //存在 起点更新为left
                }
                if(++dir[s[left]]>0) cnt--;  //如果当前要移动的是目的字符 则要cnt-- 如果++dir[s[left]]<0 则说明当前需要的字符已经多了 则不用cnt--.否则需要的字符数目就减少了 要cnt--.
                left++;  //滑动窗口左边起点右移
            }
        }
        return start==-1?"":s.substr(start, ans);  //substr(pos,len)
    }
};
// @lc code=end

