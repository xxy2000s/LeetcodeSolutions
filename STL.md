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