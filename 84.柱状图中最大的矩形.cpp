/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (41.70%)
 * Likes:    969
 * Dislikes: 0
 * Total Accepted:    95.6K
 * Total Submissions: 228.3K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          if(heights.size()==0) return 0;
          if(heights.size()==1) return heights[0];
          int ans=0;

          //前后加0 秒！
          heights.insert(heights.begin(), 0);
          heights.push_back(0);
          //添加一个单调栈
          stack<int> st;
          //让heights[0]入栈
          st.push(0);

          for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<heights[st.top()])
            {
              //如果当前遍历到的柱子高度小于栈顶，则找到右边第一个小于当前栈顶的元素，此时可以计算以栈顶元素为高的矩形面积，并且让这个元素出栈
              //由于右边加了一个0，所以最终以所有柱子为高的矩形面积都能计算到。
              int hi = heights[st.top()];
              st.pop(); //出栈
              ans = max(ans, hi*(i-st.top()-1));  //出栈了 所以要多减去一个1.
            }
            st.push(i);  //递增栈里面的元素是i，对应柱子高度的索引
          }
          return ans;
    }
};
// @lc code=end
