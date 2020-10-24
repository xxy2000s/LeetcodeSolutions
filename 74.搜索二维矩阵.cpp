/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (38.99%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    66.4K
 * Total Submissions: 169.6K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 
 * 
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [], target = 0
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 0 
 * -10^4 
 * 
 * 
 */

// @lc code=start

//1、先判断target是否在最小值和最大值的区间内 否的话false true的话下一步(说明此时target是在区间内)
//2、如果target小于第一行最后一个数 则只在第一行二分搜索即可 否则下一步
//3、对最后一列二分搜索 看能否找到target 找到了返回true,没找到返回第一个大于target的数它所在的行数pos。
//4、在pos行 如果第一个数大于target 则肯定没有 
//5、否则 在pos行二分搜索即可

//TIPS：因为行列写法不同 而此题对行的搜索偏多 所以写一个拓展的对行二分搜索的函数 并由于搜索的行数不同 多加一个参数行数pos
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      //判空
      if(matrix.size()==0 || matrix[0].size()==0) return false;
      int m=matrix.size();
      int n=matrix[0].size();

      //肯定没有的情况
      if(target<matrix[0][0] || target>matrix[m-1][n-1])    return false;

      //在第一行查
      if(target<matrix[0][n-1])  
      {
          return binSearch(matrix, target, 0, n-1, 0);
      }

      //在最后一列找对应位置 找到返回 否则在第一个大于target的数所在那一行找
      else
      {
        //对最后一列进行二分搜索
        int left = 0;
        int right = m-1;
        int pos=0;
        while(left<right)
          {
            int mid = left+((right-left)>>1);
            if(matrix[mid][n-1]==target) return true;
            else if(matrix[mid][n-1]>target) right=mid-1;
            else left=mid+1;
          }
          //找到返回true
          if(matrix[left][n-1]==target) return true;
          //如果当前的值小于target 那么下一个一定大于target 所以 pos=left+1 否则pos=left
          else if(matrix[left][n-1]<target) pos = left+1;
          else  pos = left;

          //如果该行第一个数就大于target 就返回false省的二分搜索
          if(matrix[pos][0]>target) return false;
          //在之前确定的pos行进行二分搜索即可
          return binSearch(matrix, target, 0, n-1, pos);

      }
      }

      //行二分搜索 多了一个pos参数 代表第几行
      bool binSearch(vector<vector<int>> & matrix, int target, int left, int right, int pos)
      {
          while(left<right)  //left right都可取 且无等号 所有后面left = right了 要单独讨论一下left处的值 然后再返回
          {
            int mid = left+((right-left)>>1);
            if(matrix[pos][mid]==target) return true;
            else if(matrix[pos][mid]>target) right=mid-1;
            else left=mid+1;
          }

          if(matrix[pos][left]==target) return true;
          else return false;
      }
    
};
// @lc code=end

