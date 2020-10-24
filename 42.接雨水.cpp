/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (52.66%)
 * Likes:    1727
 * Dislikes: 0
 * Total Accepted:    154.7K
 * Total Submissions: 293.2K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start


//本题多种解法 推荐双指针法
//水量按柱子一根一根的算
//有个特性 水量取决于高度的短板 所以由left_max和right_max判断从哪边看水量
//注意和之前那个面积题对比 反正都是取决于短板 验证可知
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        if(height.size()<=2) return ans;
        //一下都对应柱子坐标
        int left = 1;
        int right = height.size()-2;
        int left_max = 0;
        int right_max = height.size()-1;
        while(left<=right){
            //如果右边的更高，则判断左边能接多少水
            if(height[left_max]<height[right_max])
            {   //若指针指的当前位置柱子高度比之前的left_max矮，则高度差是接的雨水量
                if(height[left_max]>height[left])
                {
                    ans += (height[left_max]-height[left]);
                }
                //否则接不了水，更新left_max
                else  
                {
                    left_max = left;
                }
                //左指针右移
                left++;
            }
            //同上 逻辑相同 方向相反
            else
            {
                if(height[right_max]>height[right])
                {
                    ans += (height[right_max]-height[right]);
                }
                else
                {
                    right_max = right;
                }
                right--; //脑瘫 第一次写写成了right++。。。
            }
        }  
        return ans;  
    }
};
// @lc code=end

