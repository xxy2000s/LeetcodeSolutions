/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

//自主写 第一遍动态规划秒 
//好像同类题53 最大子序和
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        vector<int> dp(prices.size());
        int ans = 0;
        dp[0] = prices[0];
        //动态规划核心代码
        for(int i=1;i<prices.size();i++){
          prices[i]<=dp[i-1]?dp[i] = prices[i]:dp[i]=dp[i-1];
          ans = max(ans, prices[i]-dp[i]);
        }
        return ans>0?ans:0;
    }
};
// @lc code=end

