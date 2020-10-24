/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        string ans = strs[0];
        for(int i = 0;i<strs.size();i++){
            int j = 0;
            for(;j<ans.size() && j<strs[i].size();j++){
                if(ans[j] != strs[i][j])
                    break;
            }
            ans = ans.substr(0, j);
            }
            return ans;
        }
};
// @lc code=end