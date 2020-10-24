/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.83%)
 * Likes:    588
 * Dislikes: 0
 * Total Accepted:    158.1K
 * Total Submissions: 345K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
//相比上一题简单得多，就是时间复杂度O(n^2) 内存用的有点多???
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int ans=nums[0]+nums[1]+nums[2];
      if(ans-target == 0) return ans;
      int i=0;
      while(i<nums.size()-1){
        int left = i+1, right = nums.size()-1;
        while(left<right){
          int temp = nums[i] + nums[left] + nums[right];
          if(temp-target==0) return target;
          else if(abs(temp-target)>abs(ans-target))
          {
            if(temp-target>0)
              right--;
            else
              left++;
          }
          else
          {
            ans = temp;
            if(temp-target>0)
              right--;
            else
              left++;
          }
        }
        i++;
      }
      return ans;
    }
};
// @lc code=end

