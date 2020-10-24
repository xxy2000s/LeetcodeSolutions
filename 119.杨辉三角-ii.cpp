/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        for(int i=0;i<rowIndex+1;i++){
          ans[i] = 1;
          for(int j=i;j>1;j--){
              ans[j-1] = ans[j-1]+ans[j-2];
          }
        }
        return ans;
    }
};
// @lc code=end

