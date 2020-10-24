/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0;i<numRows;i++){
            ans[i] = vector<int>(i+1,0);
            ans[i][0] =  1;
            ans[i][i] =  1;
        }
        if(numRows<=2) return ans;
        for(int i=2;i<numRows;i++){
            for(int j=1;j<ans[i].size()-1;j++) ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        return ans;
    }
};
// @lc code=end
