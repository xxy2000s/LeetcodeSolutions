/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (43.10%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    153.7K
 * Total Submissions: 356K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: intervals = [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * intervals[i][0] <= intervals[i][1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size()-1;
        vector<vector<int>> ans;
        if(intervals.size() == 0) return ans;  //为空特殊情况
        if(n<1) return intervals;   //单元素就直接返回

        //看实例后自己写就默认升序做的...直接傻眼
        //后来才知道二维向量也可以排序，默认按列排序，就是每个数组中的第一个数 之后默认升序做的就没问题了
        sort(intervals.begin(), intervals.end());  
        //一般这种都要构造一个tmp 方便很多 之前想的更多 突然发现一个tmp就可以了 不用那么复杂
        vector<int> tmp = intervals[0];
        for(int i=0;i<n;i++)
        {   
           
            int l1 = tmp[0];
            int r1 = tmp[1];

            int l2 = intervals[i+1][0];
            int r2 = intervals[i+1][1];
            //当前的tmp的大数小于后一个的小数 就可以直接push当前的tmp进去了 然后tmp更新为下一个数组 如果到最后一个了 就可以再push 结束
            if(r1<l2) 
            {
                ans.push_back(tmp);
                tmp = intervals[i+1];
                if(i == n-1) ans.push_back(tmp);
            }
            //否则 tmp大数为较大的大数 小数为较小的小数 如果到最后一个了 直接push 否则不执行其他操作
            else
            {
                tmp[0] = min(l1, l2);
                tmp[1] = max(r1, r2);
                if(i == n-1) ans.push_back(tmp);
            }
        }
        return ans;
    }
};
// @lc code=end

