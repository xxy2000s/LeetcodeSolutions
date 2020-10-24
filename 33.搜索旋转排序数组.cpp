/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (39.04%)
 * Likes:    992
 * Dislikes: 0
 * Total Accepted:    178.3K
 * Total Submissions: 455.9K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
//总体还是二分法 查找指定值
//二分法不熟悉 总体还是left right设出 然后设置while(left<=right)条件循环即可 然后设mid值再更新left或right即可
//判断中间和最右边数谁大,中间大则左边有序 否则右边有序
//有序后则在新的区间再进行二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
          int left = 0;
          int right = nums.size()-1;
          while(left<=right){
          int mid = left + ((right-left)>>1);
          if(nums[mid] == target) return mid;
          else if(nums[mid]>nums[right])  //说明左边有序
          {
            if(nums[mid]>target && target>=nums[left])
              right=mid-1;
            else
              left = mid+1;
          }
          else  //说明右边有序
          {
              if(nums[mid]<target && target<=nums[right])
                  left = mid+1;
              else
                  right = mid-1;
            
          }
          }
          // if(left == right)
          // {
          //   if(nums[left] == target) return left;
          //   else return -1;
          // }
          return -1;
          }
};
// @lc code=end

