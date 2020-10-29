/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode-cn.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (37.71%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    31.9K
 * Total Submissions: 84K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 
 * 
 * 
 * 注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。
 * 
 */

// @lc code=start

//和56题思路相似又有不同。
//28ms 48.88% runtime 5.77%memory usage
//考虑优化内存使用
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      //为空的情况可以直接push插入的数组 然后返回
        if(intervals.size() == 0) 
        {
          intervals.push_back(newInterval);
          return intervals;
        }
        int n = intervals.size()-1;
      //设立一个tmp数组 初始化为要插入的数组。
      //应该可以不设tmp 直接在newInterval上操作优化
      //memory usage少了 但速度又慢了....
        vector<int> tmp = newInterval; 
      //返回的答案 这里可以优化
        vector<vector<int>> ans;

        //注意：由原始二维向量size为1的特殊情况推断 可以等于n
        for(int i=0;i<=n;i++){
          int l1 = intervals[i][0];
          int r1 = intervals[i][1];

          int l2 = tmp[0];
          int r2 = tmp[1];

          //如果当前循环到的数组最大小于要插入的最小
          //那直接把当前的数组push 如果到了最后一个
          //还要把要插入的数组push进去 结束
          if(r1<l2)  
          {
              ans.push_back(intervals[i]);
              if(i == n) ans.push_back(tmp);
          }
          else
          {   
            //如果当前的最小大于要插入的最大
            //push要插入的 然后往后循环 把后面的都push
            //此时已经满足 直接break结束
              if(l1>r2)
              {
                  ans.push_back(tmp);
                  for(int j=i;j<=n;j++)
                    ans.push_back(intervals[j]);
                  break;
              }
              //否则 更新要插入的数组 最大取大 最小取小
              else
              {
                  tmp[0] = min(l1, l2);
                  tmp[1] = max(r1, r2);
                  //如果已经到最后 直接push 结束了
                  if(i == n) ans.push_back(tmp);
              }
          }
        }
        return ans;

    }
};
// @lc code=end

