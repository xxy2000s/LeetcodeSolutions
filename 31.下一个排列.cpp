/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.54%)
 * Likes:    681
 * Dislikes: 0
 * Total Accepted:    92.4K
 * Total Submissions: 267.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start

//1、从后往前遍历 找到满足A[i-1]<A[i]的i
//2、从最后往前直到i遍历 找到满足比A[i-1]值大的最小值A[sw]
//3、交换A[i-1]和A[sw] 再把i直到最后的一组数升序(此时肯定是降序排列，所以只需reverse即可)排列
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        // for(;i>0;i--){
        //   if(nums[i]>nums[i-1])
        //   {
        //     break;
        //   }
        // }

        //break的话就不会执行那个i--了
        //如果for里面一直不break, 会执行i--

        while(i>0 && nums[i]<=nums[i-1]){
          i--;
        }


        if(i==0) 
        {
          reverse(nums.begin(), nums.end());
        }
        else 
        {
          for(int j = nums.size()-1;j>0;j--){
          if(nums[i-1]<nums[j])
          {
            swap(nums[i-1], nums[j]);
            break;
          }
        }
          reverse(nums.begin()+i, nums.end());
        }
    }
};
// @lc code=end

