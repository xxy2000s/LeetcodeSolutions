/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return nums.size();
        }
        int p = 0;
        int q = 1;
        while(q<nums.size()){
        if(nums[p] == nums[q]){
            q++;
        }
        else{
            nums[++p]= nums[q];
            q++;
        }
        }
        return ++p;
    }
};
// @lc code=end

