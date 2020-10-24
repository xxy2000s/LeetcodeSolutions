/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (54.38%)
 * Likes:    483
 * Dislikes: 0
 * Total Accepted:    127.9K
 * Total Submissions: 235.1K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size();
        int bsize = b.size();
        int carry = 0;
        //先凑成一样的字符串长度 以免溢出
        while(asize<bsize){
          a = '0' + a;
          asize++;
        }
        while(asize>bsize){
          b = '0' + b;
          bsize++;
        }
        for(int i = asize-1;i>=0;i--){
          int sum = a[i] - '0' + b[i] - '0' + carry;  //ascii 码运算
          carry = sum/2;  //进位
          a[i] = sum%2 + '0';  //更新当前值
        }
        if(carry>0)   //有溢出
        {
          a = '1' + a;
        }
        return a;
    }
};
// @lc code=end

