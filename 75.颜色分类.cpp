/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (55.39%)
 * Likes:    678
 * Dislikes: 0
 * Total Accepted:    143.8K
 * Total Submissions: 253.4K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

// @lc code=start
//计数排序思路简单 但是不符合一次遍历
//快排 多路快排可以
//我的完全是一次双指针 + 折腾 有点麻烦...
class Solution {
public:
    void sortColors(vector<int>& nums) {

        //快速排序
        //分为三个区间 
        if(nums.size()==0) return;
        int l=0;
        int r=nums.size()-1;
        int tmp=0;
        while(tmp<=r)
        {
          if(nums[tmp]==0)
          {
              swap(nums[tmp], nums[l]);
              tmp++;  //被换的数不可能是2 所以tmp可以直接后移
              l++;
          }
          else if(nums[tmp]==2)
          {
              swap(nums[tmp], nums[r]);
              r--;  //因为被换的数可能是2 注意这里tmp不能往前走了 否则换的是0就不好处理 要对当前再判断一次
          }
          else
          {
            tmp++;
          }
        }


        // if(nums.size()==0) return;
        // int r=nums.size()-1;
        // int l=0;
        // int tmp=-1;
        // while(l<=r)
        // {
        //   //左指针对应值为0
        //   //如果之前有1的tmp标记 则互换 否则直接右移
        //   if(nums[l]==0) 
        //   {
        //     if(tmp!=-1)
        //     {
        //       nums[tmp++] = 0;
        //       nums[l++] = 1;
        //     }
        //     else l++;
        //   }

        //   //如果左指针对应值为2 
        //   //1、右指针对应值为2 右指针左移
        //   //2、右指针对应值为0 左右指针对应值互换 右指针左移
        //   //   左边情况:之前有一(tmp坐标为第一个1) 则与tmp处的1互换,tmp++
        //   //   左指针右移 若无1 则直接左指针右移
        //   //3、右指针对应值为1 左右指针对应值互换 右指针左移 
        //   //   左边情况:之前有一 则左指针右移。无一则更新tmp为当前坐标左指针右移
        //   else if(nums[l]==2)
        //   {
        //     if(nums[r]==2)
        //       r--;
        //     else if(nums[r]==0)
        //       {
        //         nums[r--]=2;
        //         if(tmp!=-1)
        //         {
        //           nums[tmp++]=0;
        //           nums[l++]=1;
        //         }
        //         else nums[l++]=0;
        //       }
        //     else
        //     {
        //       nums[r--] = 2;
        //       if(tmp!=-1)
        //       {
        //           nums[l++]=1;
        //       }
        //       else 
        //       { 
        //         tmp = l;
        //         nums[l++]=1;
        //       }
        //     }
        //   }
        //   //如果左指针对应值为1
        //   //1、右指针为2 右指针左移
        //   //2、右指针为0 则左右指针处值互换
        //   //   左边情况：有1的标记 标记处值改为0 tmp++ 左指针右移
        //   //            之前无1的tmp标记 则左指针右移
        //   //3、右指针为1 
        //   //   左边情况：之前有1的标记 左指针右移
        //   //            无1的标记 则tmp改为当前 左指针右移             
        //   else
        //   {
        //     if(nums[r]==2)
        //       r--;
        //     else if(nums[r]==0)
        //       {
        //         nums[r]=1;
        //         if(tmp!=-1)
        //         {
        //           nums[tmp++]=0;
        //           nums[l++]=1;
        //         }
        //         else nums[l++]=0;
                
        //       }
        //     else
        //     {
        //       if(tmp!=-1)
        //       {
        //         l++;
        //       }
        //       else
        //       {
        //         tmp = l++;
        //       }
        //     }
        //   }
        // }


        
    }
};
// @lc code=end

