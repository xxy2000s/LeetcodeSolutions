/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)
        {
            return 0;
        }        
        if(nums.size()==1)
        {
            if(nums[0] == val)
        {
            return 0;
        }
            else 
            return 1;
        }
        int p=0;
        int q=1;
        while(q<nums.size()){
            if(nums[q] == val)
            {
                q++;
            }
            else 
            {
                if(nums[p] == val)
                {
                    nums[p] = nums[q];   ///sb "="写成"=="
                }
                else                   ///sb 直接else不需要再if
                {
                    nums[++p] = nums[q];
                }
                q++;
            }
        }
        if(nums[p] == val)
        {
            return 0;
        }
        else return ++p;
    }
};
// @lc code=end

