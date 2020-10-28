/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.57%)
 * Likes:    2649
 * Dislikes: 0
 * Total Accepted:    340.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
//犹豫不决先排序，步步逼近双指针

//hhhh碰到一个大坑了
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        //int k=0;
        if(nums[0]>0) return ans;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]>0)
                break;
            int t = i+1;
            int j = nums.size()-1;
            while(t<j){
                long long x = static_cast<long long>(nums[i]);
                long long y = static_cast<long long>(nums[t]);
                long long z = static_cast<long long>(nums[j]);
                if(x+y+z==0)
                {   
                    ans.push_back({nums[i], nums[t], nums[j]});
                    //ans[k++] = [nums[i], nums[t], nums[j]];
                    while(t<j&&nums[t+1] == nums[t] )
                    {
                        t++;
                    }
                    while(t<j&&nums[j-1] == nums[j])
                    {
                        j--;
                    }
                    t++;
                    j--;
                }
                if(x+y+z>0)
                {
                    j--;
                }
                if(x+y+z<0)   
                {
                    t++;
                }
            }
            while( i<nums.size()-1 && nums[i]==nums[i+1])
            {
                i++;
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end

