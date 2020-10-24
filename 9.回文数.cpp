/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
        return false;}
        long orgin_x = x;
        long rev_x = 0;
        while(x!=0){
            rev_x = rev_x*10+x%10;
            x = x/10;
        }
        return rev_x == orgin_x;
    }
};
// @lc code=end

