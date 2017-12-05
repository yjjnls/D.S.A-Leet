# Algorithms

-   [Algorithms](#algorithms)
    -   [Binary Search](#binary-search)
        -   [iteration](#iteration)
        -   [recursion](#recursion)
        -   [**LeetCode**](#leetcode)
    -   [Divide and Conquer](#divide-and-conquer)
        -   [**LeetCode**](#leetcode)
    -   [kth element and get median](#kth-element-and-get-median)
        -   [意义](#%E6%84%8F%E4%B9%89)
        -   [难点](#%E9%9A%BE%E7%82%B9)
        -   [**LeetCode**](#leetcode)
        -   [kth element (todo)](#kth-element-todo)
    -   [String (todo)](#string-todo)

## Binary Search

### iteration

```cpp
int BinarySearch(std::vector<int> &data, int target)
{
    // termiantor
    if (data.empty())
        return -1;//或者返回其他的

    int low = 0;
    int high = data.size() - 1;

    // important 1
    while (low <= high)
    {
        // important 2
        int mid = low + ((high - low) >> 1);

        if (data[mid] == target)
            return mid;
        else if (data[mid] < target)
            // important 1
            low = mid + 1;
        else
            // important 1
            high = mid - 1;
    }

    return -1;
}
```

-   terminator 返回什么一定要确认清楚
-   important 1 也可以写成如下形式，但是一定要对应起来，否则可能出现死循环

```cpp
    while(low < high)
    {
        ...
        low = mid;
        ...
        high = mid;
    }
```

-   important 2 求mid一定要注意
    如果用以下形式

```cpp
    int mid = (start + end)/2;
```

其中，start+end可能会溢出。而用以下形式又不够高效

```cpp
    int mid = start + (end - start)/2;
```

-   如果是浮点数，则比较时要用 abs(data[mid]-target)&lt;10^-5（小于一个指定的精度）
-   ★查找所有位置
    **上述二分查找代码在找到第一个目标时就会返回结果，但是如果数组中目标值有多个，如何返回它们的个数？** 上述代码中，有两个地方会返回
    > > while (low &lt;= high)

> > if (data[mid] == target)

如果在第二个判断条件不返回，而是记录之后继续查找，直到**low > high**时才返回，这样最后跳出循环时，**if(data[mid] == target)** 中的mid就是target最后一次出现的位置。
**这样子同时找到target第一次和最后一次位置的复杂度为O(log n)，而用线性遍历则是O(n)。**

### recursion

```cpp
int BinarySearch(std::vector<int> &data, int target)
{
    // termiantor
    if (data.empty())
        return -1;//或者返回其他的

    int low = 0;
    int high = data.size() - 1;

    return BinarySearchRecursion(data, target, low, high);
}

int BinarySearchRecursion(std::vector<int> &data, int target, int low, int high)
{
    // recursion terminator
    if (low > high)
        return -1;

    // current level processing
    int mid = low + ((high - low) >> 1);
    if (data[mid] == target)
        return mid;

    //drill down
    if (data[mid] < target)
        BinarySearchRecursion(data, target, mid + 1, high);
    else
        BinarySearchRecursion(data, target, low, mid - 1);
}
```
### C++实现
`lower_bound()`返回第一个大于等于val的位置  
`upper_bound()`返回第一个大于val的位置  
`binary_search()`是否存在val  


### **LeetCode**

-   50 Pow(x,n)
-   69 Sqrt(x)
-   4 Median of Two Sorted Arrays
-   230 Kth Smallest Element in a BST
-   300 Longest Increasing Subsequence


## Divide and Conquer

### **LeetCode**

-   23 Merge k Sorted Lists

* * *

## kth element and get median

### 意义

首先，取median可以看作是去kth element的特例，k=n/2取整。  
同时，median可以把原数据集划分成两个规模相仿的子集，**能够高效地确定中位数，将直接关系到采用分治策略的算法能否高效地实现，比如二分法。**

### 难点

对于有序的数组，可以通过下标来直接访问median，时间复杂度为O(1)。  
对于有序的链表，通过两个快慢指针来寻找median，时间复杂度为O(n)。此处也可能是一些排序的树形结构，比如红黑树，通过next方法遍历迭代器来获取median。  
对于无序的数据，如果先排序，再寻找median，那么时间复杂度为O(nlogn)，那么基于此的分治算法，时间复杂度不会低于：
T(n) = nlogn +2T(n/2) = O(n(logn)^2)
median的难度在于**避免全排序的前提下**，在O(nlogn)时间内找到median  

### **LeetCode**

-   4 Median of Two Sorted Arrays  
-   295 Find Median from Data Stream  
-   480	Sliding Window Median  

-   215 Kth Largest Element in an Array
-   230 Kth Smallest Element in a BST 

从295题可以看出，有以下几种求中值的方法：  
1. 每次整体排序，然后求中值，整体时间复杂度O(n^2logn)，单次为O(nlogn)，太高。  
2. 用BST来存储，在排好序的结构中，用中序遍历（或者迭代器）来求中值O(n)。这样每次只需要部分排序，但是get median时间复杂度为O(n)，整体时间复杂度会是O(nlogn)+O(n)，单次为O(logn)+O(n)。例如480的solution 1和230。  
3. 用两个heap或者priority queue，get median时间复杂度为O(1)，调整时间复杂度为O(logn)，只需要部分排序，整体时间复杂度O(nlogn)+O(1)，单次为O(logn)+O(1)。例如295中的solution 3和480中的solution 2。**虽然方法3和方法1的时间复杂度一样，但是方法1是全排序，在数据量大时是完全不能接受的，而堆的调整是部分排序。**  
4. 具体算法见295的solution 4。单次时间复杂度为O(logn)+O(1)。例如4的solution 3c和295的solution 4 [ref](https://leetcode.com/problems/find-median-from-data-stream/solution/)。  

todo

* * *

### kth element (todo)

* * *

## String (todo)

todo
kmp
