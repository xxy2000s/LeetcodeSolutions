/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (35.90%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    42.7K
 * Total Submissions: 118.7K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 * 
 * 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
 * 
 * 示例 1:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 0
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 3
 * 输出: false
 * 
 * 进阶:
 * 
 * 
 * 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
 * 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
    if(nums.size()==0) return false;
    int lo = 0;
    int hi = nums.size()-1;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        //左边有序
        if(nums[mid]>nums[hi])
        {
            if(nums[mid]==target) return true;
            //这个要筛一下条件 考虑全面一点
            else if (nums[mid]<target || nums[lo]>target) lo=mid+1;
            else return binarySearch(lo, mid-1, nums, target);
        }
        //右边有序
        else if(nums[mid]<nums[hi])
        {
            if(nums[mid]==target) return true;
            else if(nums[mid]>target || nums[hi]<target) hi=mid-1;
            else return binarySearch(mid+1, hi, nums, target);
        }
        else  //无法判断哪边有序
        {
            if(nums[mid]==target) return true;
            else hi--;   //只需最后的往前移即可 但这可能局部复杂度为Ｏ(n)
        }
         
    }
    return false;
    }

    bool binarySearch(int lo, int hi, vector<int>&nums, int target)
    {
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target) hi = mid-1;
            else lo = mid+1;
        }
        return false;
    }
};
// @lc code=end

