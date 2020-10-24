/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (40.39%)
 * Likes:    609
 * Dislikes: 0
 * Total Accepted:    138.1K
 * Total Submissions: 341.4K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start
//lower_bound和upper_bound两点不同 
//1、判断条件中的等号 nums[mid]>=target nums[mid]>target;
//2、最后返回的值一个是lo 另一个是lo-1;

//注意：当lower_bound和upper_bound的返回值一样的时候，说明这个元素不存在。
class Solution {
public:
    int n;
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ans(2,-1);
      if(nums.size()==0) return ans;
      n = nums.size();
      int left = left_bound(nums, target);
      int right = right_bound(nums, target);
      ans[0] = left;
      ans[1] = right-1;   //返回的right是第一个大于target的索引，所以减1是最后一个target的索引
      return left==right?vector<int>{-1, -1}:ans;  
      //如果left==right，
      //则意味着第一个target的索引和第一个大于target的索引相等 矛盾
      // 则没有指定值    
    }


//C++ lower_bound  找到第一个target的索引
    int left_bound(vector<int>& nums, int target){
          int lo=0;
          int ri=n;
          while(lo<ri){
            int mid = lo+((ri-lo)>>1);
            if(nums[mid]>=target) ri = mid;  //判断条件带等号 与upper_bound的第一个不同
            else lo=mid+1;
          }
          return lo;
    }

//C++ upper_bound  找到第一个大于target的数的索引 所以最后一个target的索引应该要减1
    int right_bound(vector<int>& nums, int target){
          int lo=0;
          int ri=n;  //注意 左开右闭
          while(lo<ri){   //注意 不取等
            int mid = lo+((ri-lo)>>1);
            if(nums[mid]>target) ri=mid;   //不带等号
            else lo=mid+1; 
          }
          return lo;
    }
};
// @lc code=end

