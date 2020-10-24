/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (40.25%)
 * Likes:    812
 * Dislikes: 0
 * Total Accepted:    92.9K
 * Total Submissions: 230.6K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1,2,0]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
 * 
 */
//原地哈希
//关键是让等于i+1的数字回到数组地址为i-1的位置
//然后while对每个数字都判断一下，包括交换后的 否则为if的话会跳脱出去，那交换后的当前数字就找不到正确地址了。
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int temp=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0 && nums[i]<=nums.size() && nums[nums[i] - 1] != nums[i])  
            //当前位置的元素放的不对也不能直接移动，否则就会造成死循环。如果当前位置放置的对，那么要移动过去的地方就是当前位置，所以说要移动到的地方的元素放的对不对其实已经包含了当前位置放置的对不对
            //有点绕
            //nums[i]-1 != i 这是当前元素位置不对
            //nums[nums[i]-1] != nums[i] 是目标位置元素也不对。可见包含了当前元素不对的情况。

            //nums[i]-1为当前的num[i]所要到的位置，所以要是此处的值不等于num[i]，就代表所要换的位置的元素位置也不对。 所以判断条件为nums[nums[i]-1] != nums[i]

            //若条件改为nums[i]-1=i则不行，在[1,1]这种情况会runtime error
            //不仅是看当前的是否满足交换就交换
            //更要看被换的位置是否以经处于正确位置，是否能换。
            {
                temp = nums[nums[i] - 1];   //目标地址上的值
                nums[nums[i] - 1] = nums[i]; //将目标地址的值换为当前值
                nums[i] = temp;//当前地址的值改为被换的元素值
            }
        }

        for(int i=0;i<nums.size();i++){
          if(nums[i]!=i+1)
           return i+1;
        }
        return nums.size()+1;
    }
};
// @lc code=end

