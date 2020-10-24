/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (69.96%)
 * Likes:    1514
 * Dislikes: 0
 * Total Accepted:    276.7K
 * Total Submissions: 395.4K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */

// @lc code=start
//不需要额外空间指空间复杂度O(1) 由此想到位运算
// 1、交换律：a ^ b ^ c <=> a ^ c ^ b

// 2、任何数于0异或为任何数 0 ^ n => n

// 3、相同的数异或为0: n ^ n => 0


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int i=0;i<nums.size();i++){
          temp = temp^nums[i];  //由交换律性质，此句就是所有的一起异或，最后就得到那个单独的数。
        }
        return temp;
    }
};
// @lc code=end

