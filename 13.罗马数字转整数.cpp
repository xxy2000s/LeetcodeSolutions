/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> hsmap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
    int result = 0;
    for(int i=0;i<s.length();++i)
    {
        hsmap[s[i]]<hsmap[s[i+1]] ? result -= hsmap[s[i]]:result+=hsmap[s[i]];
    }
    return result;
    }
};
// @lc code=end

