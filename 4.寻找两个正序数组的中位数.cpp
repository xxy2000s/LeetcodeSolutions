/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (38.79%)
 * Likes:    3266
 * Dislikes: 0
 * Total Accepted:    267.9K
 * Total Submissions: 690.3K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
 * 
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
//先把两个数组存到一个新数组中，然后返回对应的值
//存的过程逐个判断赋值，等循环结束
//然后再把剩下的那个数组的剩下的值赋给新数组

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           int m = nums1.size();
           int n = nums2.size();
           vector<int> ans(m+n);
           int j=0;
           int k=0;
           int i=0;
           for(;i<m && j<n;i++){
               if(nums1[i]<=nums2[j])
               {
                   ans[k++] = nums1[i];
               }
               else
               {
                   ans[k++] = nums2[j];
                   j++;
                   i--;
               }
           }
           if(j==n)
           {
               for(;i<m;i++){
                   ans[k++] = nums1[i];
               }
           }
           if(i==m)
           {
               for(;j<n;j++){
                   ans[k++] = nums2[j];
               }
           }
           return (m+n)%2==0?double(ans[(m+n)/2-1]+ans[(m+n)/2])/2:ans[(m+n)/2]; 
    }
};
// @lc code=end

