/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.39%)
 * Likes:    745
 * Dislikes: 0
 * Total Accepted:    212.7K
 * Total Submissions: 330.2K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

      // //直接调库函数的sort......
      //   if(nums.size()==0) return 0;
      //   sort(nums.begin(), nums.end());
      //   return (nums[nums.size()-k]);

      //用快排实现一下


      int n = nums.size();
      int l = 0;
      int r = nums.size()-1;
      while(l<=r)
      {
          int target = partition(nums, l, r);  //随机抽取最左边的数快排
          //n-k就是升序所要找的对应索引
          if(n-k==target) return nums[target];
          else if(n-k>target) l=target+1; //要找的索引大于当前target 在右边找
          else r = target-1;  //否则在左边找
      }
      return 0;
    }

    /**
     * 在数组 nums 的子区间 [left, right] 执行 partition 操作，返回 nums[left] 排序以后应该在的位置
     * 在遍历过程中保持循环不变量的语义
     * 1、[left + 1, j] < nums[left]
     * 2、(j, i] >= nums[left]
     * 3、最后把nums[left]和nums[j]交换 
     * 4、此时[left, j - 1] < pivot, nums[j] = pivot, [j + 1, right] >= pivot
     */
    int partition(vector<int>& nums, int left, int right)
      {   
          int pivot = nums[left];
          //初始化返回的索引j为left
          int j = left;   
          //之后swap之前j是左边最后一个小于nums[left]的索引 
          for(int i=left+1;i<=right;i++)
          {
            if(nums[i]<pivot)
            {
              j++;
              swap(nums, i, j);
            }
          }
          // 在之前遍历的过程中，满足 [left + 1, j] < pivot，并且 (j, i] >= pivot
          swap(nums, left, j);
           // 交换以后 [left, j - 1] < pivot, nums[j] = pivot, [j + 1, right] >= pivot
          return j;
      }

    void swap(vector<int>&nums, int index1, int index2)
      {
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
      }
};
// @lc code=end

