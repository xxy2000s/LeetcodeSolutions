/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size())
        {
            return -1;
        }
        if(needle == "")
        {
            return 0;
        }
        int m = haystack.size();
        int n = needle.size();
        int i =0;
        for(;i<=m-n;i++){        //这里把条件i<=m-n改成i<m就会出错。想想为啥？？
            int j=0;            //关键就是上面那个条件如果放宽了就有一个错误。
            for(;j<n;j++){
                if(haystack[i+j] != needle[j])
                    break;
                if(j==n-1 && haystack[i+j]==needle[j])   //验证满足返回i
                    return i;
            }
        }
        return -1;
    }
};
// @lc code=end

