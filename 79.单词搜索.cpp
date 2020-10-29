/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (43.56%)
 * Likes:    659
 * Dislikes: 0
 * Total Accepted:    115.5K
 * Total Submissions: 264.6K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0 || board[0].size()==0 || word.size()==0) return false;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> mark(m, vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(backTracking(board, word, i, j, 0, mark))
                    return true;
            }
        }
        return false;
    }

    int dir[4][4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool backTracking(vector<vector<char>>& board, string word, int i, int j, int index, vector<vector<bool>> &mark)
    {        
        if(index == word.size()-1 ) return word[index] == board[i][j];
        if(word[index] == board[i][j])
        {
            mark[i][j] = 1;
            for(int k=0;k<4;k++)
            {
                int new_i = i+dir[k][0];
                int new_j = j+dir[k][1];
                if(new_i>=0&&new_i<board.size() && new_j>=0&&new_j<board[0].size() && !mark[new_i][new_j])
                    if(backTracking(board, word, new_i, new_j, index+1, mark))
                        return true;
            }
            mark[i][j] = 0;
            
        }   
        return false;     
    }
};
// @lc code=end

