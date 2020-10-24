/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //贪心：
        //time-consumption: O(n)
        //memory-consumption: O(n)

        // int ans = nums[0];
        // int sum = 0;
        // for(int i=0;i<nums.size();i++){
        //   sum+=nums[i];
        //   ans = ans>sum?ans:sum;
        //   if(sum<0)    //抛弃和为负的子序列
        //   {
        //     sum = 0;
        //   }
        // }
        // return ans;

        //dp动态规划 :time-consumption: O(n)
        int result = INT_MIN;
        int numsize = nums.size();
        vector<int> dp(numsize);
        dp[0] = nums[0];
        result = dp[0];
        for(int i=1;i<numsize;i++){
          dp[i] = max(nums[i], dp[i-1]+nums[i]);  //此句为动态规划的核心 和贪心类似
          result = max(dp[i], result );
            //历史最大值都实时更新为result 相当于贪心法中的ans
        }
        return result;
    }

    //分治法好像O(nlogn)更复杂
};
// @lc code=end

