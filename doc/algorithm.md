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

* terminator 返回什么一定要确认清楚
* important 1 也可以写成如下形式，但是一定要对应起来，否则可能出现死循环
```cpp
    while(low < high)
    {
        ...
        low = mid;
        ...
        high = mid;
    }
```
* important 2 求mid一定要注意
如果用以下形式
```cpp
    int mid = (start + end)/2;
```
其中，start+end可能会溢出。而用以下形式又不够高效
```cpp
    int mid = start + (end - start)/2;
```
* 如果是浮点数，则比较时要用 abs(data[mid]-target)<10^-5（小于一个指定的精度）
* ★查找所有位置
**上述二分查找代码在找到第一个目标时就会返回结果，但是如果数组中目标值有多个，如何返回它们的个数？** 上述代码中，有两个地方会返回
>> while (low <= high)

>> if (data[mid] == target)

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
* 50 Pow(x,n)
* 69 Sqrt(x)

## kth element and get median
todo

## String
todo