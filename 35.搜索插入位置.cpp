/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
//basic version 
//time consumption O(n)
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(nums[i]>=target){
    //             return i;
    //         }
    //     }
    //     return nums.size();


//enhanced version 
//binary search 
//time consumption O(logn)
        auto first = nums.begin();
        auto last = nums.end();
        while(first<last){
            auto mid = first + ((last-first)>>1);
            if(*mid<target)
            {
                first = mid+1;
            }
            else last = mid;
        }
        return first-nums.begin();
    }
};
// @lc code=end