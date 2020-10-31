/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 *
 * https://leetcode-cn.com/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (35.92%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    5.8K
 * Total Submissions: 16.1K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。
 * 
 * 例如：
 * 
 * 
 * [2,3,4]，中位数是 3
 * [2,3]，中位数是 (2 + 3) / 2 = 2.5
 * 
 * 
 * 给你一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1
 * 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。
 * 
 * 窗口位置                      中位数
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 * ⁠1 [3  -1  -3] 5  3  6  7      -1
 * ⁠1  3 [-1  -3  5] 3  6  7      -1
 * ⁠1  3  -1 [-3  5  3] 6  7       3
 * ⁠1  3  -1  -3 [5  3  6] 7       5
 * ⁠1  3  -1  -3  5 [3  6  7]      6
 * 
 * 
 * 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
 * 与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
      vector<double> ans;
      if(nums.size()==0) return ans;
      int left=0;
      int right=k;
      //由于可能testcase [2147483647,2147483647] k=2
      //发生溢出 所以window设置为long long类型
      deque<long long> window;

      //插入排序
      //通过upper_bound lower_bound(底层都是二分法实现)产生一个迭代器
      //lower_bound准确找到该删的节点 upper_bound找到该插入的节点
      for(int i=0;i<k;i++){
        deque<long long>::iterator insert_p = upper_bound(window.begin(), window.end(), nums[i]);
        //deque的insert要传迭代器和val。
        window.insert(insert_p, nums[i]);
      }

      //ans为double类型 除以2.0使long long变为double
      ans.push_back((window[k/2]+window[(k-1)/2])/2.0);
      for(int i=k;i<nums.size();i++){
        deque<long long>::iterator delete_p = lower_bound(window.begin(), window.end(), nums[i-k]);
        //erase会删除多个同值的 所以必须传元素的迭代器。
        window.erase(delete_p);

        deque<long long>::iterator insert_p = upper_bound(window.begin(), window.end(), nums[i]);
        window.insert(insert_p, nums[i]);

        ans.push_back((window[k/2]+window[(k-1)/2])/2.0);
      }
      return ans;
    }
};
// @lc code=end

