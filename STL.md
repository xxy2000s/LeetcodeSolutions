## unordered_set

**find()**:An iterator to the element, if the specified value is found, or unordered_set::end if it is not found in the container.

如果找到对应元素,则返回一个对应元素的迭代器。如果没找到,则返回它的end();

```c++
unordered_set <char> dp;
if(dp.find('a') != dp.end()) cout<<"a in dp";
else cout<<"a not in dp";
```

### 函数层级结构
- Brief Introduction
- Parameters
- Return Vaule
- Example
- Complexity
- Iterator validity





## map
**实例：** [leetcode-3.无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();
        //用map来实现
        int ans =0;
        int start=0;
        int end = 0;
        map<char,int> lookup;
        for(;end<s.size();end++){
          if(lookup.find(s[end]) != lookup.end())  //s[end]在lookup中
          {
            //返回s[end]的迭代器 ->second访问它的值
            int tmp = lookup.find(s[end])->second;
            if(start<tmp)
              start = tmp;
            lookup.erase(s[end]);  //map的insert方法忽略重复key。而非替换所以要erase之前的key
          }
          if(ans<end-start+1)
            ans = end-start+1;
        //要插入键值对。用pair类型
          lookup.insert(pair<char,int>(s[end], end+1));  
        }
        return ans;
    }
};
```

- **find():** 找到对应元素则返回对应迭代器,否则返回map::end
- 对每个键值对访问方法：->first ->second
- **insert():** 
  - insert( pair< , >  () ) 插入键值对
  - map的insert方法会忽略重复key，而不是替换

- [pair用法](http://www.cplusplus.com/reference/utility/pair/)




## unordered_map
>unordered_map和map类似，都是存储的key-value的值，可以通过key快速索引到value。
不同的是unordered_map不会根据key的大小进行排序，存储时是根据key的hash值判断元素是否相同，即unordered_map内部元素是无序的，而map中的元素是按照二叉搜索树存储，进行中序遍历会得到有序遍历。
所以使用时map的key需要定义operator<。而unordered_map需要定义hash_value函数并且重载operator==。
但是很多系统内置的数据类型都自带这些，那么如果是自定义类型，那么就需要自己重载operator<或者hash_value()了。

**结论：** 如果需要内部元素自动排序，使用map，不需要排序使用unordered_map




>unordered_map可类比于Python中的字典。其实现使用了哈希表，可以以O(1)的时间复杂度访问到对应元素，但缺点是有较高的额外空间复杂度。
与之对应，STL中的map对应的数据结构是红黑树，红黑树内的数据时有序的，在红黑树上查找的时间复杂度是O(logN)，相对于unordered_map的查询速度有所下降，但额外空间开销减小。



## String
**substr():** paremeter:  (pos, len);





## queue

### 基本操作

```c++
#include<queue>
queue<int> q;
q.push(x);  //  入队列
q.pop();    //  出队列
q.front();  //  访问队首元素
q.back();   //  访问队尾元素
q.empty();  //  判断队列是否为空
q.size();   //  访问队列中的元素个数
```



## deque

### 基本知识

**front():** 返回第一个元素的引用。这个值就等于元素值。可直接修改。

>双端队列和普通队列最大的不同在于，它允许我们在队列的头尾两端都能在 O(1)O(1) 的时间内进行数据的查看、添加和删除。

>与队列相似，我们可以利用一个双链表实现双端队列。双端队列最常用的地方就是实现一个长度动态变化的窗口或者连续区间，而动态窗口这种数据结构在很多题目里都有运用。

### 基本操作

```c++
deque<int> q;
cout<<q.front()<<endl;//返回第一个元素的引用。这个值就等于元素值。可直接修改。
q.push_back()
q.push_front()
q.pop_back()
q.pop_front()

```

### 实例
[leetcode-239.滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)
```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size()==0) return ans;
        deque<int> window;  //存储的是数的索引
        for(int i=0;i<nums.size();i++){
          //window.front()<=i-k是防止最大的那个元素已经不在窗口
          while(!window.empty() && window.front()<=i-k){
            window.pop_front(); 
          }
          //若当前遍历的元素大于存在队列中的 则队列中的出栈
          while(!window.empty() && nums[i]>nums[window.back()]){
            window.pop_back();
          }
          window.push_back(i);
          if(i>=k-1) ans.push_back(nums[window.front()]);
        }
        return ans;
    }
};
```

## 滑动窗口(Sliding Window)
[总结(Conclusion)](https://blog.csdn.net/qq_43152052/article/details/102840715)
### 滑动窗口思想：
①窗口由两个指针构成，一个左指针left，一个右指针right，然后[left,right]表示的索引范围是一个窗口了。

②右指针right的功能是用来扩展窗口：当窗口内的条件没有达到题目要求时，我们需要不断移动右指针right直到窗口内的条件第一次满足题目要求为止。

③左指针left的功能是用来缩小窗口的：当窗口内的条件已满足题目条件或多于题目条件时（窗口溢出），我们缩小窗口，也就是左指针left需要右移直到窗口条件不满足为止。这时，我们需要记录当前窗口的大小，并更新目前为止满足条件的最小窗口记录。之后，再次扩展右指针right，使得窗口满足题目的条件。

注：滑动窗口用来处理连续满足一定条件的连续区间的性质（长度等）问题的，两个指针都起始于原点，并一前一后向终点前进。

### 框架
```c++
func movingWindow() {
    /* 1. 初始化窗口数据结构，用于记录窗口内的信息 */
    first, last := 0, 0    // 窗口的左右边界
    for last < len(s) {
        /* 2. 把 last 指向的元素加入窗口 */
        for first < len(s) && /* 3. 判断当前窗口内的元素是否符合条件 */ {
            /* 4.a 在这写更新窗口最小值的代码 */
            /* 5. 把 first 指向的元素移出窗口 */
            first++
        }
        /* 4.b 在这写更新窗口最大值的代码 */
        last++
    }
}

```

### 实例
[leetcode480.滑动窗口中位数](https://leetcode-cn.com/problems/sliding-window-median/)
>这里我们使用multiset来求出中位数（因为multiset底层使用的是二叉搜索树BST的数据结构，插入和删除元素的时间复杂度为O(logn)），利用multiset的自排序功能可以很快求出中位数。multiset作为大小为k的滑动窗口，每次插入新插入元素，需将窗口移动。若新插入的元素小于mid指向的元素，则需要将mid左移（因为新插入的元素比中位数小，那么中位数肯定会被拉低）；插入一个元素后，我们也需要删除一个元素，若需要删除的元素小于mid指向的元素，那么我们应该将mid右移。注意：对于删除元素，我们不能使用erase根据value来删除，因为这样会删除多个值一样的元素，所以我们应该使用lower_bound来找到第一个不小于目标值的数，通过iterator来删掉确定的一个数字。
关于next()与prev()函数的解释：[Here](https://blog.csdn.net/qq_43152052/article/details/102610540)


## TIPs
- 长度为k的有序向量的**中位数求法**：无论奇偶,都是( num[k/2]+num[(k-1)/2])/2 也即**索引为(size-1)/2和size/2处值和的平均**
- **中间的数mid**一般为k/2,k为偶数时为偏后的那一个中间数
- **一些初始化方法**：multiset<double> window(nums.begin(),nums.begin()+k);
- **创建iterator对象**。如 
  - ```c++
    vector<int> a(20,1);
    vector<int>::iterator tmp = upper_bound(a.begin(), a.end(), val;
    ```
## 常用函数：
```c++
//range [first,last)
//parameters (first, last, val)
//return iterator
lower_bound(); //first position that not less than the value
upper_bound(); //first position that greater than the value

// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
```


>