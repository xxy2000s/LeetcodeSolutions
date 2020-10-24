/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> comp_stack;
        for(int i=0;i<s.size();i++){
            if(comp_stack.empty() || s[i]=='[' || s[i]=='{' || s[i]=='(' )
            {
                comp_stack.push(s[i]);
            }
            else if(comp_stack.top() == '[' && s[i]==']')
            {
                comp_stack.pop();
            }
            else if(comp_stack.top() == '{' && s[i]=='}')
            {
                comp_stack.pop();
            }
            else if(comp_stack.top() == '(' && s[i]==')')
            {
                comp_stack.pop();
            }
            else{
                return false;
            }

        }
        return comp_stack.empty();
    }
};
// @lc code=end

