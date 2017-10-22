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
        int mid = low + (high - low) >> 1;

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
* 
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
    int mid = low + (high - low) >> 1;
    if (data[mid] == target)
        return mid;

    //drill down
    if (data[mid] < target)
        BinarySearchRecursion(data, target, mid + 1, high);
    else
        BinarySearchRecursion(data, target, low, mid - 1);
}
```

